#include <stdio.h>

int search(int* nums, int numsSize, int target) {
	int left = 0, right = numsSize - 1;
	if (nums[left] == target) return left;
	if (nums[right] == target) return right;
	while (left <= right) {
		int mid = (left + right) >> 1;
		if (nums[mid] == target)
			return mid;
		if (nums[left] <= nums[mid])
			if (nums[mid] > target && target >= nums[left])
				right = mid - 1;
			else
				left = mid + 1;
		else
			if (nums[mid] < target && target <= nums[right])
				left = mid + 1;
			else
				right = mid - 1;
	}
	return -1;
}

int main() {
	{
		int nums[] = { 4,5,6,7,8,1,2,3 };
		int target = 8;
		printf("%d\n", search(nums, sizeof(nums) / sizeof(int), target));
	}
	{
		int nums[] = { 1,3,5 };
		int target = 5;
		printf("%d\n", search(nums, sizeof(nums) / sizeof(int), target));
	}
	{
		int nums[] = { 1,3 };
		int target = 3;
		printf("%d\n", search(nums, sizeof(nums) / sizeof(int), target));
	}
	{
		int nums[] = { 4,5,6,7,0,1,2 };
		int target = 4;
		printf("%d\n", search(nums, sizeof(nums) / sizeof(int), target));
	}
	{
		int nums[] = { 5,1,3 };
		int target = 5;
		printf("%d\n", search(nums, sizeof(nums) / sizeof(int), target));
	}
	{
		int nums[] = { 1 };
		int target = 0;
		printf("%d\n", search(nums, sizeof(nums) / sizeof(int), target));
	}
	{
		int nums[] = { 3,1 };
		int target = 1;
		printf("%d\n", search(nums, sizeof(nums) / sizeof(int), target));
	}
	{
		int nums[] = { 4,5,6,7,8,1,2,3 };
		int target = 7;
		printf("%d\n", search(nums, sizeof(nums) / sizeof(int), target));
	}
	system("PAUSE");
	return 0;
}