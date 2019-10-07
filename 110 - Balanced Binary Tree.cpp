/*
 110. Balanced Binary Tree
 Easy
*/

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }

    int height(TreeNode* root)
    {
        if (!root)
            return 0;
        int left = height(root->left);
        int right = height(root->right);
        if (left == -1 || right == -1 || abs(left - right) > 1)
            return -1;
        else
            return max(left, right) + 1;
    }
};