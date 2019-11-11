/*
 100. Same Tree (Easy)

*/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> todo;
        TreeNode* pp = nullptr, * qq = nullptr;
        todo.push(p);
        todo.push(q);
        while (!todo.empty())
        {
            pp = todo.front();
            todo.pop();
            qq = todo.front();
            todo.pop();

            if (pp == nullptr && qq == nullptr)
                continue;
            if (pp == nullptr || qq == nullptr)
                return false;
            if (pp->val != qq->val)
                return false;

            todo.push(pp->left);
            todo.push(qq->left);
            todo.push(pp->right);
            todo.push(qq->right);
        }
        return true;
    }
};