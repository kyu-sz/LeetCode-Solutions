#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
	int *ans = (int*)malloc(matrixRowSize * matrixColSize * sizeof(int));

	if (matrixColSize == 1 && matrixRowSize == 1) {
		ans[0] = matrix[0][0];
		return ans;
	}

	int *to_fill = ans;

	int y = 0, x = 0;
	int phase = (matrixColSize == 1) ? 1 : 0;
	while (1) {
		switch (phase & 3)
		{
		case 0:
			while (x < matrixColSize - (phase >> 2) - 1)
				*to_fill++ = matrix[y][x++];
			++phase;
			if (y >= matrixRowSize - (phase >> 2) - 1) {
				*to_fill++ = matrix[y][x];
				return ans;
			}
			break;
		case 1:
			while (y < matrixRowSize - (phase >> 2) - 1)
				*to_fill++ = matrix[y++][x];
			++phase;
			if (x <= (phase >> 2)) {
				*to_fill++ = matrix[y][x];
				return ans;
			}
			break;
		case 2:
			while (x > (phase >> 2))
				*to_fill++ = matrix[y][x--];
			++phase;
			if (y <= (phase >> 2) + 1) {
				*to_fill++ = matrix[y][x];
				return ans;
			}
			break;
		case 3:
			while (y > (phase >> 2) + 1)
				*to_fill++ = matrix[y--][x];
			++phase;
			if (x >= matrixColSize - (phase >> 2) - 1) {
				*to_fill++ = matrix[y][x];
				return ans;
			}
			break;
		}
	}
}

int main() {
	{
		int matrixRowSize = 1;
		int matrixColSize = 2;
		int matrix[][2] = { {2,3} };

		int **p = (int**)malloc(sizeof(int*) * matrixRowSize);
		for (int i = 0; i < matrixRowSize; ++i)
			p[i] = matrix[i];

		int* ans = spiralOrder(p, matrixRowSize, matrixColSize);
		for (int i = 0; i < matrixRowSize * matrixColSize; ++i)
			printf("%d ", ans[i]);
		puts("");
		free(ans);

		free(p);
	}
	{
		int matrixRowSize = 1;
		int matrixColSize = 3;
		int matrix[][100] = { { 6, 9, 7 } };

		int **p = (int**)malloc(sizeof(int*) * matrixRowSize);
		for (int i = 0; i < matrixRowSize; ++i)
			p[i] = matrix[i];

		int* ans = spiralOrder(p, matrixRowSize, matrixColSize);
		for (int i = 0; i < matrixRowSize * matrixColSize; ++i)
			printf("%d ", ans[i]);
		puts("");
		free(ans);

		free(p);
	}
	system("PAUSE");
	return 0;
}