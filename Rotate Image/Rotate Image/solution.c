void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
	int temp;
	int n = matrixRowSize - 1;
	int r = matrixRowSize >> 1;
	for (int i = 0; i <= r; ++i) {
		for (int j = i; j < n - i; ++j) {
			temp = matrix[i][j];
			matrix[i][j] = matrix[n - j][i];
			matrix[n - j][i] = matrix[n - i][n - j];
			matrix[n - i][n - j] = matrix[j][n - i];
			matrix[j][n - i] = temp;
		}
	}
}