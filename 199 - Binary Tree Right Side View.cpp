/*
 199. Binary Tree Right Side View (M)
 
 Notes:
 Approach 1 : BFS
 Always only store the right-most node.
 Time: O(n)
 Space: O(n)

 Approach 2 : DFS
 A little bit tricky, if traverse depth > vector's size, push node val into vector, and first recusive the
 right node then left node to ensure the vector always have the right-most node. (left node isn't important 
 if there have right node in the same depth)
 Time: O(n)
 Space: O(n)

*/

// Approach 1 : BFS
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};

        vector<int> res;
        queue<TreeNode*> todo;
        todo.push(root);
        while (!todo.empty())
        {
            int size = todo.size();
            for (int i = 0; i < size; i++)
            {
                root = todo.front();
                todo.pop();

                if (root->left)
                    todo.push(root->left);
                if (root->right)
                    todo.push(root->right);

                if (i == size - 1)
                    res.push_back(root->val);
            }
        }
        return res;
    }
};


// Approahc 2: DFS 
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        DFS(root, 1, res);
        return res;
    }

    void DFS(TreeNode* root, int depth, vector<int>& res)
    {
        if (!root)
            return;

        if (depth > res.size())
            res.push_back(root->val);

        DFS(root->right, depth + 1, res);
        DFS(root->left, depth + 1, res);
    }
};