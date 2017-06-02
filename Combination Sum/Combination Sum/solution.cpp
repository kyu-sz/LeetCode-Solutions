#include <vector>

using namespace std;

class Solution {
	void dfs(vector<vector<int>>& ans, vector<int>& solution, const vector<int>& candidates, int target, int ptr = 0) {
		if (target == 0) {
			ans.push_back(solution);
			return;
		}
		if (ptr == candidates.size())
			return;
		int try_cnt = 0;
		while (target >= 0) {
			dfs(ans, solution, candidates, target, ptr + 1);
			solution.push_back(candidates[ptr]);
			target -= candidates[ptr];
			++try_cnt;
		}
		while (try_cnt--)
			solution.pop_back();
	}

public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> ans;
		vector<int> solution;
		solution.reserve(candidates.size());
		dfs(ans, solution, candidates, target);
		return ans;
	}
};