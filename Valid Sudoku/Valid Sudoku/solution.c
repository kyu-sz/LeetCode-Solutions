#ifdef _WIN32
#define bool int
#define false 0
#define true 1
#endif

#include <stdio.h>

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
	if (boardRowSize > 9 || boardColSize > 9 || !boardRowSize || !boardColSize)
		return false;

	// check cols, rows and characters.
	bool col_check[10][10] = { false };
	bool sub_box_check[3][3][10] = { false };
	for (int i = 0; i < boardRowSize; ++i) {
		bool row_check[10] = { false };
		for (int j = 0; j < boardColSize; ++j) {
			char x = board[i][j];
			if (x != '.') {
				if (x > '9' || x < '1')
					return false;
				x -= '0';
				if (row_check[x] || col_check[j][x])
					return false;
				bool* sub_box_ptr = sub_box_check[i / 3][j / 3];
				if (sub_box_ptr[x])
					return false;
				row_check[x] = true;
				col_check[j][x] = true;
				sub_box_ptr[x] = true;
			}
		}
	}

	return true;
}

int main() {
	{
		char board[][11] = {
			".87654321","2........","3........","4........","5........","6........","7........","8........","9........"
		};
		printf("%d\n", isValidSudoku(board, 9, 9));
	}

	{
		char board[][11] = {
			"......5..",
			".........",
			".........",
			"93..2.4..",
			"..7...3..",
			".........",
			"...34....",
			".....3...",
			".....52.."
		};
		printf("%d\n", isValidSudoku(board, 9, 9));
	}

	system("PAUSE");
	return 0;
}