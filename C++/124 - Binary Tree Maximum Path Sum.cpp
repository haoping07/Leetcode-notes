/*
 124. Binary Tree Maximum Path Sum (H)

 Notes:
 Approach 1 : Divide-and-conquer (Postorder)
 Solution ref from HuaHua(https://youtu.be/9ZNky1wqNUw)
 Check left and right child and get max.
 Time: O(n)
 Space: O(n)
 
*/

// Approach 1 : Divide-and-conquer
class Solution {
public:
	int maxPathSum(TreeNode* root) {
		int res = INT_MIN;
		maxPathSum(root, res);
		return res;
	}

	int maxPathSum(TreeNode* root, int& res)
	{
		if (!root) return 0;
		int left = max(0, maxPathSum(root->left, res));
		int right = max(0, maxPathSum(root->right, res));
		int sum = left + right + root->val;
		res = max(res, sum);
		return max(left, right) + root->val;
	}
};