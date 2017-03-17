#include <stdio.h>

void nextPermutation(int* nums, int numsSize) {
	int swapBuf;
#define swap(a,b) {swapBuf=(a);(a)=(b);(b)=swapBuf;}
	for (int i = numsSize - 2; i >= 0; --i)
		if (nums[i] < nums[i + 1]) {
			int left;
			if (numsSize - i > 128) {
				left = i + 1;
				int right = numsSize - 1;
				int mid = ((left + right) >> 1) + 1;
				while (left < right) {
					if (nums[mid] > nums[i]) left = mid;
					else right = mid - 1;
					mid = ((left + right) >> 1) + 1;
				}
			}
			else {
				for (int j = numsSize - 1; ; --j)
					if (nums[i] < nums[j]) {
						left = j;
						break;
					}
			}
			swap(nums[i], nums[left]);
			int span = (numsSize - i) >> 1;
			for (int k = 1; k <= span; ++k)
				swap(nums[i + k], nums[numsSize - k]);
			return;
		}

	// such arrangement is not possible. rearrange it as the lowest possible order (ascending order).
	int span = numsSize >> 1;
	for (int i = 0; i < span; ++i)
		swap(nums[i], nums[numsSize - 1 - i]);
	return;
}

int main() {
	{
		int nums[] = { 1,3,2 };
		int numsSize = sizeof(nums) / sizeof(int);
		nextPermutation(nums, numsSize);
		for (int i = 0; i < numsSize; ++i)
			printf("%d ", nums[i]);
		puts("");
	}
	return 0;
}