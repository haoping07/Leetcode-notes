/*
 103. Binary Tree Zigzag Level Order Traversal
 Medium
*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> result;
        queue<TreeNode*> todo;
        todo.push(root);
        int curLevel = 0;
        while (!todo.empty())
        {
            int size = todo.size();
            vector<int> tmp;
            for (int i = 0; i < size; i++)
            {
                root = todo.front();
                todo.pop();
                if (root->left)
                    todo.push(root->left);
                if (root->right)
                    todo.push(root->right);
                tmp.push_back(root->val);
            }

            if (curLevel % 2 == 1)
                reverse(tmp.begin(), tmp.end());
            result.push_back(tmp);
            curLevel++;
        }
        return result;
    }
};