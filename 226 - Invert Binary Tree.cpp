/*
 226. Invert Binary Tree
 Easy
*/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> todo;
        todo.push(root);
        while (!todo.empty())
        {
            TreeNode* entry = todo.front();
            todo.pop();
            if (entry)
            {
                todo.push(entry->left);
                todo.push(entry->right);
 
                TreeNode* tmp = entry->left;
                entry->left = entry->right;
                entry->right = tmp;
            }
        }
        return root;
    }
};
