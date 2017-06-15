#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> ans;
		ans.reserve(strs.size());
		unordered_map<string, int> groups;

		{
			hash<string> hasher;
			int cnt[26];
			string token;
			for (auto str : strs) {
				memset(cnt, 0, sizeof(int) * 26);
				for (auto c : str)
					++cnt[c - 'a'];
				token.resize(str.length());
				auto p = token.begin();
				for (int i = 0; i < 26; ++i)
					for (int j = 0; j < cnt[i]; ++j)
						*p++ = i;

				if (groups.count(token))
					ans[groups[token]].push_back(str);
				else {
					groups[token] = ans.size();
					ans.push_back(vector<string>({ str }));
				}
			}
		}

		return ans;
	}
};

int main() {
	{
		vector<string> strs({ "eat","tea","tan","ate","nat","bat" });
		auto ans = Solution().groupAnagrams(strs);
		for (auto group : ans) {
			for (auto str : group)
				cout << str << ' ';
			cout << endl;
		}
		cout << endl;
	}
	system("PAUSE");
	return 0;
}