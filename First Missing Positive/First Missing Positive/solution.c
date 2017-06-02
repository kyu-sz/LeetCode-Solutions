#include <stdio.h>

int firstMissingPositive(int* nums, int numsSize) {
	int temp, x;
#define swap(a,b) {temp=a;a=b;b=temp;}
	for (int i = 0; i < numsSize; ++i)
		while ((x = nums[i]) > 0 && x <= numsSize && x != nums[x - 1])
			swap(nums[i], nums[x - 1]);
	for (int i = 0; i < numsSize; ++i)
		if (nums[i] != i + 1)
			return i + 1;
	return numsSize + 1;
}

int main() {
	{
		int nums[] = { 4,1,2,3 };
		printf("%d\n", firstMissingPositive(nums, sizeof(nums) / sizeof(int)));
	}
	{
		int nums[] = { 3,3,1,4,0 };
		printf("%d\n", firstMissingPositive(nums, sizeof(nums) / sizeof(int)));
	}
	{
		int nums[] = { 1,2,0 };
		printf("%d\n", firstMissingPositive(nums, sizeof(nums) / sizeof(int)));
	}
	{
		int nums[] = { 3,4,-1,1 };
		printf("%d\n", firstMissingPositive(nums, sizeof(nums) / sizeof(int)));
	}
	{
		int nums[] = { 1,1 };
		printf("%d\n", firstMissingPositive(nums, sizeof(nums) / sizeof(int)));
	}
	{
		int nums[] = { 0,2,2,1,1 };
		printf("%d\n", firstMissingPositive(nums, sizeof(nums) / sizeof(int)));
	}
	system("PAUSE");
	return 0;
}