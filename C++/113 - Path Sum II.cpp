/*
 113. Path Sum II (M)

 A1: Preorder (top-down) recursion
 Preorder the tree, use a vector to store the current path, if fullfill the
 given sum, save the path to result
 Time: O(n)
 Space: O(depth)

*/

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> sub;
        
        pathSum(root, sum, sub, res);
        return res;
    }
    
    void pathSum(TreeNode* root, int sum, vector<int>& sub, vector<vector<int>>& res) {
        if (!root) return;
        
        // Add the current node in to path list
        sub.push_back(root->val);
        
        // Check if fullfill the given sum when it is a leaf node
        if (!root->left && !root->right && root->val == sum) {
            res.push_back(sub);
        }
        
        // If not, update the sum and move to the next level
        if (root->left) pathSum(root->left, sum - root->val, sub, res);
        if (root->right) pathSum(root->right, sum - root->val, sub, res);
        
        // Update the path for the next node
        sub.pop_back();
    }
};
