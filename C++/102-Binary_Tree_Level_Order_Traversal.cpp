/*
 102. Binary Tree Level Order Traversal (M)

 BFS
 Before each level: the number of node in queue is the number of node in that level.
 In each level: push the left and right child into queue, if any.
 After each level: push the vector that contains all nodes in that level into result vector.
 O(n),O(n)

 DFS
 If the depth of the current node is greater than the result vector size, push_back a 
 vector contains current node's value. Else, put the current node's value into the
 corresponding index of result vector.
 [Imagine this method as 'fill the stairs']
 O(n),O(n)

*/

// BFS
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root) return {};
        vector<vector<int>> ret;
        queue<TreeNode *> todo;
        todo.push(root);
        while (!todo.empty())
        {
            int size = todo.size();
            vector<int> sub;
            for (int i = 0; i < size; i++)
            {
                root = todo.front();
                todo.pop();
                sub.push_back(root->val);
                if (root->left) todo.push(root->left);
                if (root->right) todo.push(root->right);
            }
            ret.push_back(sub);
        }
        return ret;
    }
};

// DFS
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ret;
        DFS(root, 1, ret);
        return ret;
    }

    void DFS(TreeNode *root, int depth, vector<vector<int>> &ret)
    {
        if (!root) return;
        if (depth > ret.size()) ret.push_back({root->val});
        else ret[depth - 1].push_back(root->val);
        DFS(root->left, depth + 1, ret);
        DFS(root->right, depth + 1, ret);
    }
};