#include <cstdio>
#include <cmath>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	int traverse(TreeNode* node) {
		int left_height = node->left ? traverse(node->left) : 0;
		int right_height = node->right ? traverse(node->right) : 0;
		if (left_height == -1 || right_height == -1 || abs(left_height - right_height) > 1)
			return -1;
		return ((left_height > right_height) ? left_height : right_height) + 1;
	}
public:
    bool isBalanced(TreeNode* root) {
		return root ? (traverse(root) >= 0) : true;
    }
};