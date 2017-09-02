#include <vector>
#include <iostream>
#include <climits>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
	struct Case {
		const string* word_;
		vector<const Case*> prev_;
		bool is_from_begin_;
		int depth_;
		int index_in_word_list_;
		Case(const string* word, bool is_from_begin, int depth, int index_in_word_list, const Case* prev = nullptr) :
			word_(word), is_from_begin_(is_from_begin), depth_(depth), index_in_word_list_(index_in_word_list)
		{
			if (prev) prev_.push_back(prev);
		}
	};

	inline bool isTransform(string a, string b) {
		bool found_diff = false;
		int len = a.length();
		for (int i = 0; i < len; ++i)
			if (a[i] != b[i])
				if (found_diff)
					return false;
				else
					found_diff = true;
		return found_diff;
	}

	void track(const Case* c, vector<const string*>& rec, vector<vector<const string*>>& store) {
		bool divided = false;
		rec.push_back(c->word_);
		if (c->prev_.size())
			for (auto p : c->prev_)
				track(p, rec, store);
		else
			store.push_back(rec);
		rec.pop_back();
	}
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		vector<vector<string>> ans;

		int word_len = beginWord.length();

		wordList.push_back(beginWord);
		int num_words = wordList.size();

		// Precompute transformation relations.
		unordered_map<string, int> word_set;
		for (int i = 0; i < num_words; ++i)
			word_set[wordList[i]] = i;

		// First check if endWord is in wordList.
		if (!word_set.count(endWord))
			return ans;
		int end_word_loc = word_set[endWord];

		// Two-end BFS.
		vector<Case> from_begin, from_end;
		from_begin.reserve(num_words + 1);
		from_end.reserve(num_words + 1);
		from_begin.push_back(Case(&beginWord, true, 0, num_words - 1));
		from_end.push_back(Case(&endWord, false, 0, end_word_loc));
		int left_from_begin = 0, right_from_begin = 1;
		int left_from_end = 0, right_from_end = 1;

		// Records where each word is used in BFS queue from begin or end.
		Case** usage = new Case*[num_words];
		memset(usage, 0, sizeof(Case*) * num_words);
		usage[num_words - 1] = &from_begin[0];
		usage[end_word_loc] = &from_end[0];

		bool matched = false;
		vector<pair<Case, Case>> connection;
		while (left_from_begin < right_from_begin && left_from_end < right_from_end) {
			int num_new = 0;
			for (int i = left_from_begin; i < right_from_begin; ++i) {
				const auto& cur = from_begin[i];
				const string& word = *cur.word_;
				for (int j = 0; j < word_len; ++j) {
					string new_word = word;
					for (char c = 'a'; c <= 'z'; ++c)
						if (c != word[j]) {
							new_word[j] = c;
							auto it = word_set.find(new_word);
							if (it != word_set.end()) {
								int new_index = it->second;
								if (!usage[new_index]) {
									// Unused.
									from_begin.push_back(Case(&wordList[new_index], true, cur.depth_ + 1, new_index, &cur));
									usage[new_index] = from_begin.data() + right_from_begin + num_new++;
								}
								else if (usage[new_index]->is_from_begin_) {
									// Used by queue from front.
									if (usage[new_index]->depth_ == cur.depth_ + 1)
										usage[new_index]->prev_.push_back(&cur);
								}
								else {
									// Used by queue from end. Matched!
									matched = true;
									connection.push_back(pair<Case, Case>(Case(&wordList[new_index], true, cur.depth_ + 1, new_index, &cur), *usage[new_index]));
								}
							}
						}
				}
			}
			if (matched)
				break;
			left_from_begin = right_from_begin;
			right_from_begin += num_new;

			num_new = 0;
			for (int i = left_from_end; i < right_from_end; ++i) {
				const auto& cur = from_end[i];
				const string& word = *cur.word_;
				for (int j = 0; j < word_len; ++j) {
					string new_word = word;
					for (char c = 'a'; c <= 'z'; ++c)
						if (c != word[j]) {
							new_word[j] = c;
							auto it = word_set.find(new_word);
							if (it != word_set.end()) {
								int new_index = it->second;
								if (!usage[new_index]) {
									// Unused.
									from_end.push_back(Case(&wordList[new_index], false, cur.depth_ + 1, new_index, &cur));
									usage[new_index] = from_end.data() + right_from_end + num_new++;
								}
								else if (usage[new_index]->is_from_begin_) {
									// Used by queue from front. Matched!
									matched = true;
									connection.push_back(pair<Case, Case>(*usage[new_index], Case(&wordList[new_index], true, cur.depth_ + 1, new_index, &cur)));
								}
								else {
									// Used by queue from end.
									if (usage[new_index]->depth_ == cur.depth_ + 1)
										usage[new_index]->prev_.push_back(&cur);
								}
							}
						}
				}
			}
			if (matched)
				break;
			left_from_end = right_from_end;
			right_from_end += num_new;
		}

		for (const auto& conn : connection) {
			vector<const string*> rec;
			vector<vector<const string*>> front_paths;
			vector<vector<const string*>> end_paths;
			rec.reserve(conn.first.depth_);
			track(&conn.first, rec, front_paths);
			rec.reserve(conn.second.depth_);
			track(&conn.second, rec, end_paths);
			for (auto fp : front_paths)
				for (auto ep : end_paths) {
					vector<string> full_path;
					full_path.reserve(conn.first.depth_ + conn.second.depth_ - 1);
					for (auto it = fp.rbegin(); it != fp.rend(); ++it)
						full_path.push_back(**it);
					for (auto it = ep.begin() + 1; it != ep.end(); ++it)
						full_path.push_back(**it);
					ans.push_back(full_path);
				}
		}

		delete[] usage;
		return ans;
	}
};

int main() {
	vector<string> wordList{ "kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob" };
	auto ans = Solution().findLadders("cet", "ism", wordList);
	for (auto path : ans) {
		for (auto s : path)
			cout << s << ' ';
		cout << endl;
	}
	system("PAUSE");
	return 0;
}