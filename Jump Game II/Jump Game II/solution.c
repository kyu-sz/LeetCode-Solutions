#include <stdio.h>

#define min(a,b) ((a) < (b) ? (a) : (b))

int jump(int* nums, int numsSize) {
	if (numsSize <= 1)
		return 0;
	int steps = 0;
	for (int i = 0; i < numsSize;) {
		int limit = min(numsSize - i - 1, nums[i]);
		if (i + limit >= numsSize - 1)
			return steps + 1;
		int best = 0, bestloc = numsSize;
		for (int j = 1; j <= limit; ++j) {
			if (j + nums[i + j] > best) {
				best = j + nums[i + j], bestloc = i + j;
			}
		}
		++steps;
		i = bestloc;
	}
	return steps;
}

int main() {
	{
		int nums[] = { 5,9,3,2,1,0,2,3,3,1,0,0 };
		printf("%d\n", jump(nums, sizeof(nums) / sizeof(int)));
	}
	{
		int nums[] = { 1,2,3 };
		printf("%d\n", jump(nums, sizeof(nums) / sizeof(int)));
	}
	{
		int nums[] = { 0 };
		printf("%d\n", jump(nums, sizeof(nums) / sizeof(int)));
	}
	system("PAUSE");
	return 0;
}