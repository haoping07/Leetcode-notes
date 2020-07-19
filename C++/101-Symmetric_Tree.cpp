/*
 101. Symmetric Tree (E)

 BFS
 O(n),O(n)

 DFS
 O(n),O(n)

*/

// BFS
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root) return true;

        // Use queue to record the nodes that will be processed
        queue<TreeNode *> todo;
        todo.push(root->left);
        todo.push(root->right);

        TreeNode *p = nullptr;
        TreeNode *q = nullptr;

        while (!todo.empty())
        {
            p = todo.front();
            todo.pop();
            q = todo.front();
            todo.pop();

            if (!p && !q) continue;
            if (!p || !q) return false;
            if (p->val != q->val) return false;

            todo.push(p->left);
            todo.push(q->right);
            todo.push(p->right);
            todo.push(q->left);
        }
        return true;
    }
};

// DFS
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root) return true;
        return Check(root->left, root->right);
    }

    bool Check(TreeNode *l, TreeNode *r)
    {
        if (!l && !r) return true;
        if (!l || !r) return false;
        if (l->val != r->val) return false;
        return Check(l->left, r->right) && Check(l->right, r->left);
    }
};
