/*
 107. Binary Tree Level Order Traversal II (E)

 Notes:
   Approach 1 : BFS
   Time: O(n)
   Space: O(n)

   Approach 2 : DFS
   Ref. to Q.102
   Time: O(n)
   Space: O(n)

*/

// Approach 1 : BFS
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root)
            return {};

        vector<vector<int>> res;
        queue<TreeNode*> todo;
        todo.push(root);
        while (!todo.empty())
        {
            int size = todo.size();
            vector<int> sub;
            for (int i = 0; i < size; i++)
            {
                root = todo.front();
                todo.pop();
                
                if (root->left)
                    todo.push(root->left);
                if (root->right)
                    todo.push(root->right);

                sub.push_back(root->val);
            }
            res.push_back(sub);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


// Approach 2 : DFS
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        DFS(root, 0);
        reverse(res.begin(), res.end());
        return res;
    }

    void DFS(TreeNode* root, int depth)
    {
        if (!root)
            return;

        if (depth < res.size())
            res[depth].push_back(root->val);
        else
            res.push_back({ root->val });

        DFS(root->left, depth + 1);
        DFS(root->right, depth + 1);
    }

private:
    vector<vector<int>> res;
};