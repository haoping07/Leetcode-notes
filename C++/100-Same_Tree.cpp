/*
 100. Same Tree (E)

 A: BFS
 Push the p and q nodes together into queue, compare two nodes and push their
 children into queue respectively.
 Time: O(n)
 Space: O(n)

 A2: DFS
 Time: O(n)
 Space: O(n)

*/

// A1
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


// A2
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};