#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
	void dfs(vector<vector<string>>& ans, vector<string>& solution, int n,
		bool* row_occ, bool* col_occ, bool* left_diag, bool* right_diag,
		int row = 0, int col = 0) {
		if (row == n) {
			ans.push_back(solution);
			return;
		}
		if (col == n) {
			if (!row_occ[row])
				return;
			else
				dfs(ans, solution, n, row_occ, col_occ, left_diag, right_diag, row + 1, 0);
		}
		else {
			int lind = row - col + n - 1;
			int rind = row + col;
			if (!(row_occ[row] || col_occ[col] || left_diag[lind] || right_diag[rind])) {
				row_occ[row] = true;
				col_occ[col] = true; 
				left_diag[lind] = true;
				right_diag[rind] = true;
				solution[row][col] = 'Q';
				dfs(ans, solution, n, row_occ, col_occ, left_diag, right_diag, row, col + 1);
				row_occ[row] = false;
				col_occ[col] = false;
				left_diag[lind] = false;
				right_diag[rind] = false;
				solution[row][col] = '.';
			}
			dfs(ans, solution, n, row_occ, col_occ, left_diag, right_diag, row, col + 1);
		}
	}
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> ans;

		vector<string> solution(n, string(n, '.'));
		bool* row_occ = new bool[n];
		bool* col_occ = new bool[n];
		bool* left_diag = new bool[n << 1];
		bool* right_diag = new bool[n << 1];
		memset(row_occ, 0, sizeof(bool) * n);
		memset(col_occ, 0, sizeof(bool) * n);
		memset(left_diag, 0, sizeof(bool) * (n << 1));
		memset(right_diag, 0, sizeof(bool) * (n << 1));
		dfs(ans, solution, n, row_occ, col_occ, left_diag, right_diag);
		delete[] row_occ;
		delete[] col_occ;
		delete[] left_diag;
		delete[] right_diag;

		return ans;
	}
};

int main() {
	vector<vector<string>> ans;

	ans = Solution().solveNQueens(1);
	for (auto solution : ans) {
		for (auto row : solution)
			cout << row << endl;
		cout << endl;
	}

	ans = Solution().solveNQueens(4);
	for (auto solution : ans) {
		for (auto row : solution)
			cout << row << endl;
		cout << endl;
	}

	system("PAUSE");
	return 0;
}