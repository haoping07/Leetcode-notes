/*
 226. A Invert Binary Tree (E)

 Check if root exist
  - If yes, swap its children
  - If no, do nothing

 A1: BFS
 Time: O(n)
 Space: O(n)

 A2: DFS
 Time: O(n)
 Space: O(n)

*/

// A1
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


// A2
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
