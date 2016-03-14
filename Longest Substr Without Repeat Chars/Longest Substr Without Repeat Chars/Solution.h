#pragma once

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Solution {
	inline int max(int a, int b) {
		return a > b ? a : b;
	}
public:
	int lengthOfLongestSubstring(string s) {
		int existed_index[256];
		for (int i = 0; i < 256; ++i)
			existed_index[i] = -1;

		int best_res = 0;
		int head = 0;

		for (int i = 0; i < s.length(); ++i) {
			if (existed_index[s[i]] > -1) {
				if (best_res < i - head)
					best_res = i - head;
				head = max(head, existed_index[s[i]] + 1);
				existed_index[s[i]] = i;
			}
			existed_index[s[i]] = i;
		}

		if (s.length() - head > best_res)
			best_res = s.length() - head;

		return best_res;
	}
};