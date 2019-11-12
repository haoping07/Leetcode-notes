/*
 104. Maximum Depth of Binary Tree (Easy)
 
 Notes: Recursive, BFS
*/

// Recursive 1
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return left > right ? left + 1 : right + 1;
    }
};

// Recursive 2 (slower)
class Solution {
public:
    void DFS(TreeNode* root, int depth, int& res)
    {
        if (!root) return;
        res = max(res, depth);
        DFS(root->left, depth + 1, res);
        DFS(root->right, depth + 1, res);
    }

    int maxDepth(TreeNode* root) {
        int res = 0;
        DFS(root, 1, res);
        return res;
    }
};


// BFS
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        queue<TreeNode*> todo;
        todo.push(root);
        int count = 0;
        while (!todo.empty())
        {
            int size = todo.size();
            count++;
            for (int i = 0; i < size; i++)
            {
                root = todo.front();
                todo.pop();
                if (root->left)
                    todo.push(root->left);
                if (root->right)
                    todo.push(root->right);
            }
        }
        return count;
    }
};