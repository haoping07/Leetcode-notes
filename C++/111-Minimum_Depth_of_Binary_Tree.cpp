/*
 111. Minimum Depth of Binary Tree
 Easy
*/

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        int count = 0;
        queue<TreeNode*> todo;
        todo.push(root);
        while (!todo.empty())
        {
            int size = todo.size();
            count++;
            for (int i = 0; i < size; i++)
            {
                root = todo.front();
                todo.pop();
                if (!root->left && !root->right)
                    return count;
                if (root->left)
                    todo.push(root->left);
                if (root->right)
                    todo.push(root->right);
            }
        }
        return -1;
    }
};