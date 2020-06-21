/*
 103. Binary Tree Zigzag Level Order Traversal (M)
 
 Approach 1 : iteration
 Time: O(n)
 Space: O(n)

 Approach 2 : recursion
 Time: O(n)
 Space: O(n)

*/

// Approahc 1 : 
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        int level = 0;
        queue<TreeNode*> todo;
        todo.push(root);
        while (!todo.empty())
        {
            int size = todo.size();
            vector<int> sub;
            level++;
            for (int i = 0; i < size; i++)
            {
                root = todo.front();
                todo.pop();
                sub.push_back(root->val);
                if (root->left) todo.push(root->left);
                if (root->right) todo.push(root->right);
            }
            if (level % 2 == 0)
                reverse(sub.begin(), sub.end());
            res.push_back(sub);
        }
        return res;
    }
};


// Approahc 2 : 
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        DFS(root, 1, res);
        for (int i = 1; i < res.size(); i += 2)
            reverse(res[i].begin(), res[i].end());
        return res;
    }

    void DFS(TreeNode* root, int depth, vector<vector<int>>& res)
    {
        if (!root) return;
        if (res.size() < depth)
            res.push_back({ root->val });
        else
            res[depth - 1].push_back(root->val);
        DFS(root->left, depth + 1, res);
        DFS(root->right, depth + 1, res);
    }
};