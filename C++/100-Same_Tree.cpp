/*
 100. Same Tree (E)

 BFS
 Compare two nodes and push their children into queue, then pop out and 
 do the compare again till the end
 O(n),O(n)

 DFS
 O(n),O(n)

*/

// BFS
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        queue<TreeNode *> todo;
        todo.push(p);
        todo.push(q);
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
            todo.push(q->left);
            todo.push(p->right);
            todo.push(q->right);
        }
        return true;
    }
};

// DFS
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};