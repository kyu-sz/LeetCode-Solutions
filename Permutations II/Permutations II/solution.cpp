#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> ans;
		sort(nums.begin(), nums.end());
		ans.push_back(nums);
		int temp;
		bool flag = true;
		while (flag) {
			flag = false;
			for (int i = nums.size() - 1; i; --i)
				if (nums[i] > nums[i - 1]) {
					flag = true;
					for (int j = nums.size() - 1;; --j)
						if (nums[j] > nums[i - 1]) {
							swap(nums[i - 1], nums[j]);
							break;
						}
					int r = (nums.size() - i) >> 1;
					for (int j = 0; j < r; ++j)
						swap(nums[i + j], nums[nums.size() - j - 1]);
					ans.push_back(nums);
					break;
				}
		}

		return ans;
	}
};

int main() {
	{
		vector<int> nums = { 1,1,2 };
		auto res = Solution().permuteUnique(nums);
		for (auto arr : res) {
			for (auto v : arr) {
				cout << v << ' ';
			}
			cout << endl;
		}
	}
	system("PAUSE");
	return 0;
}