#ifdef _WIN32
#define bool int
#define true 1
#define false 0
#endif

bool canJump(int* nums, int numsSize) {
	int furthest = 0;
	for (int i = 0; i < numsSize; ++i)
		if (i > furthest)
			return false;
		else
			if (i + nums[i] > furthest)
				furthest = i + nums[i];
	return true;
}