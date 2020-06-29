/*
 101. Symmetric Tree (E)

 Ref.100

 A1: BFS
 Time: O(n)
 Space: O(n)

 A2: DFS
 Time: O(n)
 Space: O(n)

*/

// A1
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

// A2
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
