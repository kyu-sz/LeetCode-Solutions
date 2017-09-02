#include <vector>

using namespace std;

class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> dup;
		for (int x : nums) {
			int px = (x > 0 ? x : -x) - 1;
			if (nums[px] > 0)
				nums[px] = -nums[px];
			else
				dup.push_back(px + 1);
		}
		return dup;
	}
};