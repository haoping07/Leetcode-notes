/*
 226. Invert Binary Tree (E)

 Notes:
 Approach 1 : Recursion
 Time: O(n)
 Space: O(n)

 Approach 2 : Iteration
 Time: O(n)
 Space: O(n)

*/

// Approach 1 : Recursion
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        DFSInvert(root);
        return root;
    }

    void DFSInvert(TreeNode* root)
    {
        if (root)
        {
            TreeNode* tmp = root->left;
            root->left = root->right;
            root->right = tmp;
            DFSInvert(root->left);
            DFSInvert(root->right);
        }
    }
};

// Approach 1 : Iteration
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> todo;
        todo.push(root);
        TreeNode* entry = nullptr;
        while (!todo.empty())
        {
            entry = todo.front();
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
