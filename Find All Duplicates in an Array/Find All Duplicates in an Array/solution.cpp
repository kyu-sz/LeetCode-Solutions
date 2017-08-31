#include <vector>

using namespace std;

class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> dup;
		for (int i = 0; i < nums.size(); ++i) {
			while (nums[i] - 1 != i && nums[i] != -1) {
				if (nums[i] == nums[nums[i] - 1]) {
					// Found a duplicate!
					dup.push_back(nums[i]);
					nums[i] = -1;
					break;
				}
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
		return dup;
	}
};