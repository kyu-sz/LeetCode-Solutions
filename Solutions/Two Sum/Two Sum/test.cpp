#include "Solution.h"

int main() {
	vector<int> nums({ 3, 2, 4 });

	Solution solution;
	auto res = solution.twoSum(nums, 6);
	cout << "[";
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i];
		if (i + 1 < res.size())
			cout << ",";
	}
	cout << "]" << endl;

	return 0;
}