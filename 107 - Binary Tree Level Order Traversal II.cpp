/*
 107. Binary Tree Level Order Traversal II
 Easy
*/

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root)
            return {};
        vector<vector<int>> result;
        queue<TreeNode*> todo;
        todo.push(root);
        while (!todo.empty())
        {
            int size = todo.size();
            vector<int> tmp;
            for (int i = 0; i < size; i++)
            {
                root = todo.front();
                todo.pop();
                if (root->left)
                    todo.push(root->left);
                if (root->right)
                    todo.push(root->right);
                tmp.push_back(root->val);
            }
            result.push_back(tmp);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};