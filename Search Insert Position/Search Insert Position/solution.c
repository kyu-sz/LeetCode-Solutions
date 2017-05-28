#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
	if (!numsSize) return 0;
	int left = 0, right = numsSize - 1;
	while (left < right) {
		int mid = (left + right) >> 1;
		if (nums[mid] == target) return mid;
		if (nums[mid] < target) left = mid + 1;
		else right = mid;
	}
	return nums[right] >= target ? right : right + 1;
}

int main() {
	{
		int nums[] = { 1 };
		int target = 1;
		printf("%d\n", searchInsert(nums, sizeof(nums) / sizeof(int), target));
	}

	system("PAUSE");
	return 0;
}