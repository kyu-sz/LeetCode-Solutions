#include <stdio.h>
#include <cassert>

#ifdef _WIN32
#define bool int
#define false 0
#define true 1
#endif

bool dfs(char** board, int y, int x, int boardRowSize, int boardColSize, bool row[9][10], bool col[9][10], bool subbox[3][3][10]) {
	if (x == boardColSize)
		if (y == boardRowSize - 1)
			return true;
		else
			return dfs(board, y + 1, 0, boardRowSize, boardColSize, row, col, subbox);
	if (board[y][x])
		return dfs(board, y, x + 1, boardRowSize, boardColSize, row, col, subbox);
	
	bool* sb = subbox[y / 3][x / 3];
	for (int v = 1; v <= 9; ++v)
		if (!row[y][v] && !col[x][v] && !sb[v]) {
			row[y][v] = true;
			col[x][v] = true;
			sb[v] = true;
			board[y][x] = v;
			if (dfs(board, y, x + 1, boardRowSize, boardColSize, row, col, subbox))
				return true;
			board[y][x] = 0;
			row[y][v] = false;
			col[x][v] = false;
			sb[v] = false;
		}

	return false;
}

void solveSudoku(char** board, int boardRowSize, int boardColSize) {
	bool row[9][10] = { 0 }, col[9][10] = { 0 }, subbox[3][3][10] = { 0 };
	for (int i = 0; i < boardRowSize; ++i)
		for (int j = 0; j < boardColSize; ++j)
			if (board[i][j] == '.')
				board[i][j] = 0;
			else {
				int v = (board[i][j] -= '0');
				assert(v >= 1 && v <= 9);
				row[i][v] = true;
				col[j][v] = true;
				subbox[i / 3][j / 3][v] = true;
			}

	int ret = dfs(board, 0, 0, boardRowSize, boardColSize, row, col, subbox);
	assert(ret);

	for (int i = 0; i < boardRowSize; ++i)
		for (int j = 0; j < boardColSize; ++j)
			if (board[i][j] != '.')
				board[i][j] += '0';
}

int main() {
	char* board[9];
	for (int i = 0; i < 9; ++i)
		board[i] = malloc(10);
	memcpy(board[0], "..9748...", 10);
	memcpy(board[1], "7........", 10);
	memcpy(board[2], ".2.1.9...", 10);
	memcpy(board[3], "..7...24.", 10);
	memcpy(board[4], ".64.1.59.", 10);
	memcpy(board[5], ".98...3..", 10);
	memcpy(board[6], "...8.3.2.", 10);
	memcpy(board[7], "........6", 10);
	memcpy(board[8], "...2759..", 10);
	solveSudoku(board, 9, 9);
	for (int i = 0; i < 9; ++i)
		printf("%s\n", board[i]);
	for (int i = 0; i < 9; ++i)
		free(board[i]);
	system("PAUSE");
	return 0;
}