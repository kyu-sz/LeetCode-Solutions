#pragma once

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

#include <map>

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {

		vector<int> res;
		res.reserve(2);

		std::map<int, int> pair;

		for (int i = 0; i < nums.size(); ++i) {
			if (pair.find(nums[i]) != pair.end()) {
				return vector<int>({ pair[nums[i]], i });
			}
			pair[target - nums[i]] = i;
		}
			
		return vector<int>();
	}
};
