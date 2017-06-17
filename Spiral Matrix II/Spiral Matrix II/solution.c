/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n) {
	int **ans = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; ++i)
		ans[i] = (int*)malloc(sizeof(int) * n);

	if (!n)
		return ans;
	else if (n == 1) {
		ans[0][0] = 1;
		return ans;
	}

	int cnt = 0;
	int phase = 0;
	int y = 0, x = 0;
	while (1) {
		ans[y][x] = ++cnt;
		switch (phase & 3)
		{
		case 0:
			++x;
			if (x >= n - 1 - (phase >> 2))
				++phase;
			if (y >= n - 1 - (phase >> 2)) {
				ans[y][x] = cnt + 1;
				return ans;
			}
			break;
		case 1:
			++y;
			if (y >= n - 1 - (phase >> 2))
				++phase;
			if (x <= (phase >> 2)) {
				ans[y][x] = cnt + 1;
				return ans;
			}
			break;
		case 2:
			--x;
			if (x <= (phase >> 2))
				++phase;
			if (y <= (phase >> 2) + 1) {
				ans[y][x] = cnt + 1;
				return ans;
			}
			break;
		case 3:
			--y;
			if (y <= (phase >> 2) + 1)
				++phase;
			if (x >= n - 1 - (phase >> 2)) {
				ans[y][x] = cnt + 1;
				return ans;
			}
			break;
		}
	}
}