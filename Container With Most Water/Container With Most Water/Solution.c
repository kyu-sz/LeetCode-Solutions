#include <stdio.h>
#include <assert.h>

int maxArea(int* height, int heightSize) {
	int *left = height, *right = height + heightSize - 1;
	int area;
	if (*left < *right) area = *left++ * --heightSize;
	else area = *right-- * --heightSize;
	int best = area;
	while (left < right) {
		int area;
		if (*left < *right) area = *left++ * --heightSize;
		else area = *right-- * --heightSize;
		if (area > best) best = area;
	}
	return best;
}

int main() {
	{
		int height[] = { 1,2,4,3 };
		assert(maxArea(height, sizeof(height) / sizeof(int)) == 4);
	}
	{
		int height[] = { 8,10,14,0,13,10,9,9,11,11 };
		assert(maxArea(height, sizeof(height) / sizeof(int)) == 80);
	}
	return 0;
}