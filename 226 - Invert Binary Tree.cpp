/*
 226. Invert Binary Tree
 Easy
*/

// Recursive
class Solution {
public:
    void InvertNode(TreeNode* root)
    {
        if (root)
        {
            TreeNode* tmp = root->left;
            root->left = root->right;
            root->right = tmp;

            InvertNode(root->left);
            InvertNode(root->right);
        }
    }

    TreeNode* invertTree(TreeNode* root) {
        InvertNode(root);
        return root;
    }
};

// BFS
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
