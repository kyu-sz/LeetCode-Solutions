#include <stdio.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
	int* ans = (int*)malloc(2 * sizeof(int));
	*returnSize = 2;

	if (!numsSize) {
		ans[0] = ans[1] = -1;
		return ans;
	}

	// find one target.
	int left = 0, right = numsSize - 1, mid;
	while (left <= right) {
		mid = (left + right) >> 1;
		if (nums[mid] > target)
			right = mid - 1;
		else if (nums[mid] < target)
			left = mid + 1;
		else
			break;
	}

	// no target is found.
	if (nums[mid] != target) {
		ans[0] = ans[1] = -1;
		return ans;
	}

	// find left bound.
	if (nums[left] != target) {
		int left_rbound = mid;
		while (!(nums[left] < target && nums[left + 1] == target)) {
			int test = (left + left_rbound) >> 1;
			if (nums[test] < target) left = test;
			else left_rbound = test;
		}
		++left;
	}

	// find right bound.
	if (nums[right] != target) {
		int right_lbound = mid;
		while (!(nums[right] > target && nums[right - 1] == target)) {
			int test = (right + right_lbound) >> 1;
			if (nums[test] > target) right = test;
			else right_lbound = test;
		}
		--right;
	}

	ans[0] = left, ans[1] = right;
	return ans;
}

int main() {
	int retSize;
	{
		int nums[] = { 5,7,7,8,8,10 };
		int target = 8;
		int* ans = searchRange(nums, sizeof(nums) / sizeof(int), target, &retSize);
		printf("[%d, %d]\n", ans[0], ans[1]);
		free(ans);
	}
	system("PAUSE");
	return 0;
}