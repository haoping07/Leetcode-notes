/*
 144. Binary Tree Preorder Traversal (M)

 Recursion
 O(n),O(n)

 DFS
 O(n),O(n)

 BFS style DFS
 O(n),O(n)

*/

// Recursion
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        DFS(root, ret);
        return ret;
    }

    void DFS(TreeNode *root, vector<int> &ret)
    {
        if (!root) return;
        ret.push_back(root->val);
        DFS(root->left, ret);
        DFS(root->right, ret);
    }
};

// DFS
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        stack<TreeNode*> todo;
        while (!todo.empty() || root)
        {
            while (root)
            {
                ret.push_back(root->val);
                todo.push(root);
                root = root->left;
            }
            root = todo.top();
            todo.pop();
            root = root->right;
        }
        return ret;
    }
};

// BFS style DFS
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (!root) return {};
        vector<int> ret;
        stack<TreeNode*> todo;
        todo.push(root);
        while (!todo.empty())
        {
            root = todo.top();
            todo.pop();
            ret.push_back(root->val);
            if (root->right) todo.push(root->right);
            if (root->left) todo.push(root->left);
        }
        return ret;
    }
};