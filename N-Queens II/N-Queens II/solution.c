#include <stdio.h>

#ifdef _WIN32
#define bool int
#define true 1
#define false 0
#endif

void dfs(int* ans, int n, bool* row_occ, bool* col_occ, bool* left_diag, bool* right_diag, int row, int col) {
	if (col == n) {
		if (row_occ[row])
			if (row == n - 1)
				++*ans;
			else
				dfs(ans, n, row_occ, col_occ, left_diag, right_diag, row + 1, 0);
		return;
	}
	else {
		int lind = row - col + n;
		int rind = row + col;
		if (!(row_occ[row] || col_occ[col] || left_diag[lind] || right_diag[rind])) {
			row_occ[row] = col_occ[col] = left_diag[lind] = right_diag[rind] = true;
			dfs(ans, n, row_occ, col_occ, left_diag, right_diag, row, col + 1);
			row_occ[row] = col_occ[col] = left_diag[lind] = right_diag[rind] = false;
		}
		dfs(ans, n, row_occ, col_occ, left_diag, right_diag, row, col + 1);
	}
}

int totalNQueens(int n) {
	int ans = 0;

	bool* row_occ = (bool*)malloc(n * sizeof(bool));
	bool* col_occ = (bool*)malloc(n * sizeof(bool));
	bool* left_diag = (bool*)malloc((n << 1) * sizeof(bool));
	bool* right_diag = (bool*)malloc((n << 1) * sizeof(bool));
	memset(row_occ, 0, sizeof(bool) * n);
	memset(col_occ, 0, sizeof(bool) * n);
	memset(left_diag, 0, sizeof(bool) * (n << 1));
	memset(right_diag, 0, sizeof(bool) * (n << 1));

	for (int i = 0; i < (n >> 1); ++i) {
		int row = 0, col = i;
		int lind = 0 - col + n;
		int rind = row + col;

		row_occ[row] = col_occ[col] = left_diag[lind] = right_diag[rind] = true;
		dfs(&ans, n, row_occ, col_occ, left_diag, right_diag, 0, 1);
		row_occ[row] = col_occ[col] = left_diag[lind] = right_diag[rind] = false;
	}

	ans <<= 1;

	if (n & 1) {
		int special = 0;
		int row = 0, col = n >> 1;
		int lind = 0 - col + n;
		int rind = row + col;

		row_occ[row] = col_occ[col] = left_diag[lind] = right_diag[rind] = true;
		dfs(&special, n, row_occ, col_occ, left_diag, right_diag, 0, 1);
		ans += special;
	}

	free(row_occ);
	free(col_occ);
	free(left_diag);
	free(right_diag);

	return ans;
}

int main() {
	printf("%d\n", totalNQueens(1));
	system("PAUSE");
	return 0;
}