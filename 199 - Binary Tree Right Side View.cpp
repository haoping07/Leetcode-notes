/*
 199. Binary Tree Right Side View
 Medium
*/

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> result;
        queue<TreeNode*> todo;
        todo.push(root);
        while (!todo.empty())
        {
            int size = todo.size();
            for (int i = 0; i < size; i++)
            {
                root = todo.front();
                todo.pop();
                if (root->left)
                    todo.push(root->left);
                if (root->right)
                    todo.push(root->right);
                if (i == size - 1)
                    result.push_back(root->val);
            }
        }
        return result;
    }
};