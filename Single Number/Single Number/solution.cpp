#include <vector>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int buf = 0;
		for (auto x : nums)
			buf ^= x;
		return 0 ^ buf;
	}
};