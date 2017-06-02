#include <stdio.h>

int trap(int* height, int heightSize) {
	int left, right;
	for (left = 0; left < heightSize; ++left)
		if (height[left])
			break;
	if (left == heightSize) return 0;
	for (right = heightSize - 1; right > left; --right)
		if (height[right])
			break;
	if (left == right) return 0;

	int total = 0, local = 0;
	for (int i = left + 1; i <= right; ++i) {
		if (height[i] >= height[left]) {
			left = i;
			total += local;
			local = 0;
		}
		else
			local += height[left] - height[i];
	}

	if (left == right) return total;
	
	local = 0;
	for (int i = right - 1; i > left; --i) {
		if (height[i] >= height[right]) {
			right = i;
			total += local;
			local = 0;
		}
		else
			local += height[right] - height[i];
	}

	return total + local;
}

int main() {
	{
		int height[] = { 4,2,3 };
		printf("%d\n", trap(height, sizeof(height) / sizeof(int)));
	}
	{
		int height[] = { 0,1,0,2,1,0,1,3,2,1,2,1 };
		printf("%d\n", trap(height, sizeof(height) / sizeof(int)));
	}
	system("PAUSE");
	return 0;
}