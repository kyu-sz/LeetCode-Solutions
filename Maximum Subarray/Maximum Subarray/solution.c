#define max(a, b) ((a) > (b) ? (a) : (b))

int maxSubArray(int* nums, int numsSize) {
	int maxSum = nums[0], sum = max(0, nums[0]);
	for (int i = 1; i < numsSize; ++i) {
		if (sum < 0)
			sum = nums[i];
		else
			sum += nums[i];
		if (sum > maxSum)
			maxSum = sum;
	}
	return maxSum;
}