/*
 103. Binary Tree Zigzag Level Order Traversal (M)
 
 Notes:
    T: O(nodes + 2 * depth / 2)     // (2 * depth / 2): Each level at most two nodes, 
                                    // only even level (half of the depth) needs reverse 
    S: O(n)
    Use a count to track if the current level is even or odd. If even, reverse the vector in that level.
*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> todo;
        todo.push(root);
        vector<vector<int>> res;
        int level = 0;
        while (!todo.empty())
        {
            int size = todo.size();
            vector<int> tmp;
            level++;
            for (int i = 0; i < size; i++)
            {
                root = todo.front();
                todo.pop();
                tmp.push_back(root->val);
                if (root->left)
                    todo.push(root->left);
                if (root->right)
                    todo.push(root->right);
            }
            if (level % 2 == 0)
                reverse(tmp.begin(), tmp.end());
            res.push_back(tmp);
        }
        return res;
    }
};