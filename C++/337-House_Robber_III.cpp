/*
 337. House Robber III
 Medium
*/

class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> result = helper(root);
        return max(result[0], result[1]);
    }

    vector<int> helper(TreeNode* root)
    {
        if (!root)
            return { 0, 0 };
        vector<int> result{ 0, 0 };
        vector<int> left = helper(root->left);
        vector<int> right = helper(root->right);
        result[0] = max(left[0], left[1]) + max(right[0], right[1]);
        result[1] = left[0] + right[0] + root->val;
        return result;
    }
};