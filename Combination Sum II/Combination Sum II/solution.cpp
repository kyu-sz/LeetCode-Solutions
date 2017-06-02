#include <vector>
#include <algorithm>

using namespace std;

class Solution {
	void dfs(vector<vector<int>>& ans,
		vector<int>& solution, 
		const vector<int>& candidates,
		const vector<int>& link,
		int target, 
		int last_omit,
		int ptr = 0) {
		if (target == 0) {
			ans.push_back(solution);
			return;
		}
		if (ptr == candidates.size())
			return;
		dfs(ans, solution, candidates, link, target, candidates[ptr], link[ptr]);
		if (target >= candidates[ptr] && candidates[ptr] != last_omit) {
			solution.push_back(candidates[ptr]);
			dfs(ans, solution, candidates, link, target - candidates[ptr], last_omit, ptr + 1);
			solution.pop_back();
		}
	}

public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		const int numCandidates = candidates.size();

		vector<vector<int>> ans;
		vector<int> solution;
		vector<int> link;
		solution.reserve(numCandidates);
		link.resize(numCandidates);

		sort(candidates.begin(), candidates.end());
		int link_ptr = 0;
		for (int i = 1; i < numCandidates; ++i)
			if (candidates[i] != candidates[i - 1])
				while (link_ptr < i)
					link[link_ptr++] = i;
		while (link_ptr < numCandidates)
			link[link_ptr++] = numCandidates;

		dfs(ans, solution, candidates, link, target, candidates[0] - 1);
		return ans;
	}
};