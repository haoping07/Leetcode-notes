/*
 129. Sum Root to Leaf Numbers (M)

 A1: DFS
 DFS the tree and save the node value, if the node is a leaf, add it to the total sum.
 Time: O(n)
 Space: O(n)

*/

// A1
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        DFS(root, sum, 0);
        return sum;
    }
    
    void DFS(TreeNode* root, int& sum, int curSum) {
        if (!root) return;
        curSum = curSum * 10 + root->val;

        // If the node is a leaf, add the current sum to the total sum
        if (!root->left && !root->right) sum += curSum;

        // If not a leaf, move into it
        if (root->left) DFS(root->left, sum, curSum);
        if (root->right) DFS(root->right, sum, curSum);
    }
};
