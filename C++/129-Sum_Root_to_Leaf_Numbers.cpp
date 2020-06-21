/*
 129. Sum Root to Leaf Numbers
 Medium
*/

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (!root)
            return 0;
        sum = 0;
        DFS(root, 0);
        return sum;
    }
 
    void DFS(TreeNode* root, int currentSum)
    {
        currentSum = currentSum * 10 + root->val;
        if (!root->left && !root->right)
            sum += currentSum;
        if (root->left)
            DFS(root->left, currentSum);
        if (root->right)
            DFS(root->right, currentSum);
    }
 
private:
    int sum;
};
