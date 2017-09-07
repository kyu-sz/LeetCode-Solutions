#include <string>

using namespace std;

class Solution {
public:
	int minCut(string s) {
		int* odd_longest = new int[s.length()];
		int* even_longest = new int[s.length()];
		for (int i = 0; i < s.length(); ++i) {
			int offset = 1;
			while (offset <= i && i + offset < s.length() && s[i - offset] == s[i + offset])
				++offset;
			odd_longest[i] = offset;

			offset = 0;
			while (offset <= i && i + offset + 1 < s.length() && s[i - offset] == s[i + offset + 1])
				++offset;
			even_longest[i] = offset;
		}

		int* min_seg = new int[s.length()];
		for (int i = 0; i < s.length(); ++i)
			min_seg[i] = i + 1;
		min_seg[0] = 1;
		if (even_longest[0])
			min_seg[1] = 1;
		for (int i = 1; i < s.length(); ++i) {
			for (int j = 0; j < odd_longest[i]; ++j)
				if (min_seg[i - j - 1] + 1 < min_seg[i + j])
					min_seg[i + j] = min_seg[i - j - 1] + 1;
			for (int j = 0; j < even_longest[i]; ++j)
				if (min_seg[i - j - 1] + 1 < min_seg[i + j + 1])
					min_seg[i + j + 1] = min_seg[i - j - 1] + 1;
		}
		int ans = min_seg[s.length() - 1] - 1;
		delete[] odd_longest;
		delete[] even_longest;
		delete[] min_seg;
		return ans;
	}
};