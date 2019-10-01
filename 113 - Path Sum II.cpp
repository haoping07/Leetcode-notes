/*
 113. Path Sum II
 Medium
*/

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> cur;
        DFS(root, sum, cur, result);
        return result;
    }
 
    void DFS(TreeNode* root, int gap, vector<int>& cur, vector<vector<int>>& result)
    {
        if (root == nullptr)
            return;
 
        cur.push_back(root->val);
 
        if (root->left == nullptr && root->right == nullptr)
        {
            if (gap == root->val)
                result.push_back(cur);
        }
 
        DFS(root->left, gap - root->val, cur, result);
        DFS(root->right, gap - root->val, cur, result);
        cur.pop_back();
    }
};
