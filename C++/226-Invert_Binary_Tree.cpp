/*
 226. Invert Binary Tree (E)

 Swap the current node children, if their children exist, enter them and swap
 their children.

 BFS
 O(n),O(n)

 DFS
 O(n),O(n)

*/

// BFS
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root) return root;
        queue<TreeNode *> todo;
        todo.push(root);
        TreeNode *ptr = nullptr;
        while (!todo.empty())
        {
            ptr = todo.front();
            todo.pop();

            if (ptr->left) todo.push(ptr->left);
            if (ptr->right) todo.push(ptr->right);

            TreeNode *tmp = ptr->left;
            ptr->left = ptr->right;
            ptr->right = tmp;
        }
        return root;
    }
};

// DFS
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        DFSInvert(root);
        return root;
    }

    void DFSInvert(TreeNode *root)
    {
        if (!root) return;
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        DFSInvert(root->left);
        DFSInvert(root->right);
    }
};
