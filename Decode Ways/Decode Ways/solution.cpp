#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		if (s.empty()) return 0;
		int* dp = new int[s.length() + 1];
		memset(dp, 0, sizeof(int) * (s.length() + 1));
		dp[0] = 1;
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] > '9' || s[i] < '0')
				return 0;
			if (s[i] != '0')
				dp[i + 1] += dp[i];
			if (i + 1 < s.length() && (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6'))
				dp[i + 2] += dp[i];
		}
		int ans = dp[s.length()];
		delete[] dp;
		return ans;
	}
};