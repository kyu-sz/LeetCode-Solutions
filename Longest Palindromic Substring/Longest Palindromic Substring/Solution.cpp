#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Solution {
public:
	string longestPalindrome(string s);
};

string Solution::longestPalindrome(string s) {

	if (s.length() == 0)
		return "";

	string res = s.substr(0, 1);	//In case that there is only one character in s.

	for (int i = 0; i < s.length(); ++i) {
		//Odd length palindromic substr
		for (int j = 1; j <= i + 1 && i + j <= s.length(); ++j) {
			if (!(j <= i && i + j < s.length()) || s[i + j] != s[i - j]) {
				--j;
				if (((j << 1) | 1) > res.length()) {
					res = s.substr(i - j, ((j << 1) | 1));
				}
				break;
			}
		}
		//Even length palindromic substr
		for (int j = 0; j <= i + 1 && i + j + 1 <= s.length(); ++j) {
			if (!(j <= i && i + j + 1 < s.length()) || s[i + j + 1] != s[i - j]) {
				if (j > 0 && (j << 1) > res.length()) {
					res = s.substr(i - j + 1, j << 1);
				}
				break;
			}
		}
	}

	return res;
}

int main() {

	Solution solution;

	cout << solution.longestPalindrome("") << endl;
	cout << solution.longestPalindrome("a") << endl;
	cout << solution.longestPalindrome("aa") << endl;
	cout << solution.longestPalindrome("baa") << endl;
	cout << solution.longestPalindrome("aab") << endl;
	cout << solution.longestPalindrome("ccc") << endl;
	cout << solution.longestPalindrome("sdcvsbeuvsnhnjkenabanemfovo") << endl;

	return 0;
}