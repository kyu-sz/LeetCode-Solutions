/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize) {
	*returnSize = 1;
	for (int i = 2; i <= numsSize; ++i)
		*returnSize *= i;
	int **ans = malloc(*returnSize * sizeof(int*));
	for (int i = 0; i < *returnSize; ++i)
		ans[i] = malloc(numsSize * sizeof(int));

	int ans_cnt = 0;
	int *indices = malloc(numsSize * sizeof(int));
#define FILL_ANS {								\
		for (int i = 0; i < numsSize; ++i)		\
			ans[ans_cnt][i] = nums[indices[i]];	\
		++ans_cnt;								\
	}

	int temp;
	for (int i = 0; i < numsSize; ++i)
		indices[i] = i;
	FILL_ANS;
	while (ans_cnt < *returnSize) {
		for (int i = numsSize - 1; i; --i)
			if (indices[i] > indices[i - 1]) {
				int v = indices[i - 1];
				for (int j = numsSize - 1;;--j)
					if (indices[j] > v) {
						indices[i - 1] = indices[j];
						indices[j] = v;
						break;
					}
				int r = (numsSize - i) >> 1;
				for (int j = 0; j < r; ++j) {
					temp = indices[i + j];
					indices[i + j] = indices[numsSize - j - 1];
					indices[numsSize - j - 1] = temp;
				}
				break;
			}
		FILL_ANS;
	}

	free(indices);
	return ans;
}

#include <stdio.h>

int main() {
	{
		int nums[] = { 1,2,3,4 };
		int numsSize = sizeof(nums) / sizeof(int);
		int retSize;
		int **ret = permute(nums, numsSize, &retSize);
		for (int i = 0; i < retSize; ++i) {
			for (int j = 0; j < numsSize; ++j)
				printf("%d ", ret[i][j]);
			puts("");
		}
		puts("");
	}
	system("PAUSE");
	return 0;
}