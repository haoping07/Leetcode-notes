/*
 110. Balanced Binary Tree (E)

 A1: DFS (btm-up)
 Use a helper function to pass the current level, and check if it is balanced.
 The helper function return an integer rather than bool to count the level. 
 Time: O(n)
 Space: O(n)

*/

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }

    int height(TreeNode* root)
    {
        if (!root) return 0;
        int left = height(root->left);
        int right = height(root->right);
        if (left == -1 || right == -1 || abs(left - right) > 1) {
            return -1;
        }
            
        // We don't use min() because it will fail in skew tree
        return max(left, right) + 1;
    }
};
