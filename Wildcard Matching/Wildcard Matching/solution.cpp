#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		// find all alphabet strings.
		vector<pair<int, int>> alphabet_strs;
		vector<bool> arbitrary;
		vector<int> min_intervals;
		{
			bool any_wildcard = false; // if '*' exists.
			int single_wildcard = 0; // how many '?' exists.
			int num_alphabet = 0;
			for (int i = 0; i < p.length(); ++i)
				switch (p[i])
				{
				case '?':
					if (num_alphabet) {
						alphabet_strs.push_back(pair<int, int>(i - num_alphabet, num_alphabet));
						num_alphabet = 0;
					}
					++single_wildcard;
					break;
				case '*':
					if (num_alphabet) {
						alphabet_strs.push_back(pair<int, int>(i - num_alphabet, num_alphabet));
						num_alphabet = 0;
					}
					any_wildcard = true;
					break;
				default:
					if (!num_alphabet || !i) {
						arbitrary.push_back(any_wildcard);
						min_intervals.push_back(single_wildcard);
						any_wildcard = false;
						single_wildcard = 0;
					}
					++num_alphabet;
					break;
				}
			if (num_alphabet)
				alphabet_strs.push_back(pair<int, int>(p.length() - num_alphabet, num_alphabet));
			arbitrary.push_back(any_wildcard);
			min_intervals.push_back(single_wildcard);
		}

		const int num_str = alphabet_strs.size();

		vector<vector<int>> matchings;
		{
			vector<int> lps;
			matchings.resize(num_str);
			for (int i = 0; i < num_str; ++i) {
				const int& start = alphabet_strs[i].first;
				const int& len = alphabet_strs[i].second;
				const char* str = p.data() + start;

				// match the string in s by KMP.
				// construct longest prefix suffix.
				lps.resize(len);
				int cnt = 0;
				lps[0] = 0;
				for (int i = 1; i < len; ++i)
					if (str[i] == str[cnt])
						lps[i] = ++cnt;
					else
						if (cnt)
							cnt = lps[cnt - 1], --i;
						else
							lps[i] = 0;
				// match by lps.
				int s_i = 0, str_i = 0;
				while (s_i < s.length()) {
					if (s[s_i] == str[str_i]) {
						++s_i, ++str_i;
						if (str_i == len) {
							matchings[i].push_back(s_i - len);
							str_i = lps[str_i - 1];
						}
					}
					else {
						if (str_i)
							str_i = lps[str_i - 1];
						else
							++s_i;
					}
				}

				if (matchings[i].empty())
					return false;
			}
		}

		vector<int> valid_starts = { 0 };
		for (int i = 0; i < num_str; ++i) {
			vector<int> valid_ends;
			if (arbitrary[i]) {
				int first_valid = matchings[i].size();
				for (int j = 0; j < matchings[i].size(); ++j)
					if (matchings[i][j] - valid_starts[0] >= min_intervals[i]) {
						first_valid = j;
						break;
					}
				for (int j = first_valid; j < matchings[i].size(); ++j)
					valid_ends.push_back(matchings[i][j] + alphabet_strs[i].second);
			}
			else {
				for (int start : valid_starts) {
					for (int j = 0; j < matchings[i].size(); ++j)
						if (matchings[i][j] == start + min_intervals[i]) {
							valid_ends.push_back(matchings[i][j] + alphabet_strs[i].second);
							break;
						}
				}
			}
			if (valid_ends.empty())
				return false;
			valid_starts = valid_ends;
		}

		if (arbitrary[num_str])
			return s.length() - valid_starts[0] >= min_intervals[num_str];
		else {
			for (int start : valid_starts)
				if (s.length() == start + min_intervals[num_str])
					return true;
			return false;
		}
	}
};

int main() {
	printf("%d\n", Solution().isMatch("aa", "aa"));
	printf("%d\n", Solution().isMatch("aaaa", "***a"));
	printf("%d\n", Solution().isMatch("abcde", "*?*?*?*?"));
	printf("%d\n", Solution().isMatch("hi", "*?"));
	printf("%d\n", Solution().isMatch("c", "*?*"));

	printf("%d\n", Solution().isMatch("abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb",
		"**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb"));
	system("PAUSE");
	return 0;
}