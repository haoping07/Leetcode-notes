/*
 226. Invert Binary Tree (E)

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
        queue<TreeNode *> todo;
        todo.push(root);
        TreeNode *entry = nullptr;
        
        while (!todo.empty())
        {
            entry = todo.front();
            todo.pop();

            if (entry->left) todo.push(entry->left);
            if (entry->right) todo.push(entry->right);

            TreeNode *tmp = entry->left;
            entry->left = entry->right;
            entry->right = tmp;
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
