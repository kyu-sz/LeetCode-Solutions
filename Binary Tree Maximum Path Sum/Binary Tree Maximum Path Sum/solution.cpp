#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// first: best result for half path; second: best result for full path.
typedef pair<int, int> Result;

Result traverse(TreeNode* node) {
	Result best(node->val, node->val);
	if (node->left) {
		auto res = traverse(node->left);
		if (best.first < res.first + node->val)
			best.second = best.first = res.first + node->val;
		if (best.second < res.second)
			best.second = res.second;
	}
	if (node->right) {
		auto res = traverse(node->right);
		if (best.second < best.first + res.first)
			best.second = best.first + res.first;
		if (best.first < res.first + node->val)
			best.first = res.first + node->val;
		if (best.second < res.second)
			best.second = res.second;
	}
	return best;
}

class Solution {
public:
    int maxPathSum(TreeNode* root) {
		return traverse(root).second;
    }
};