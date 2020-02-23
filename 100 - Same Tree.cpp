/*
 100. Same Tree (E)

 Notes:
   Approach 1 : BFS
   Time: O(n)
   Space: O(n)

*/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> todo;
        todo.push(p);
        todo.push(q);
        while (!todo.empty())
        {
            p = todo.front();
            todo.pop();
            q = todo.front();
            todo.pop();

            if (p == nullptr && q == nullptr)
                continue;
            if (p == nullptr || q == nullptr)
                return false;
            if (p->val != q->val)
                return false;

            todo.push(p->left);
            todo.push(q->left);
            todo.push(p->right);
            todo.push(q->right);
        }
        return true;
    }
};