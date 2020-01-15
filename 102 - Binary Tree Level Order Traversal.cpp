/*
 102. Binary Tree Level Order Traversal (Medium)

 Notes:
    Tree traversal - BFS or DFS. Both work in here. O(n)
    Use BFS: Before each level: the number of node in queue is the number of node in that level.
             In each level: push the left and right child into queue, if any;
             After each level: push the vector that contains all nodes in that level into result 
             vector;
    Use DFS: If the depth of the current node is greater than the result vector size, push_back a 
             vector contains current node's value. Else, put the current node's value into the
             corresponding index of result vector;
             [Imagine this method as 'filling the stairs'] 
*/

// BFS
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> todo;
        todo.push(root);

        while (!todo.empty())
        {
            int size = todo.size();
            vector<int> vec;
            for (int i = 0; i < size; i++)
            {
                root = todo.front();
                todo.pop();
                vec.push_back(root->val);
                if (root->left)
                    todo.push(root->left);
                if (root->right)
                    todo.push(root->right);
            }
            res.push_back(vec);
        }
        return res;
    }
};

// DFS
class Solution {
public:
    void DFS(TreeNode* root, int depth, vector<vector<int>>& res)
    {
        if (!root) return;
        if (depth < res.size())
            res[depth].push_back(root->val);
        else
            res.push_back({ root->val });

        DFS(root->left, depth + 1, res);
        DFS(root->right, depth + 1, res);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        DFS(root, 0, res);
        return res;
    }
};