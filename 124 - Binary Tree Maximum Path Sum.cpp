/*
 124. Binary Tree Maximum Path Sum (Hard)

 Ref: Hua Hua: https://youtu.be/9ZNky1wqNUw
*/

class Solution {
public:
	int maxPathSum(TreeNode* root, int& res)
	{
		if (!root) return 0;
		int left = max(0, maxPathSum(root->left, res));
		int right = max(0, maxPathSum(root->right, res));
		int sum = left + right + root->val;
		res = max(res, sum);
		return max(left, right) + root->val;
	}

	int maxPathSum(TreeNode* root) {
		int res = INT_MIN;
		maxPathSum(root, res);
		return res;
	}
};