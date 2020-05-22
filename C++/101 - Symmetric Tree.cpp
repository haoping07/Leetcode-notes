/*
 101. Symmetric Tree (E)

 Ref. 100

 Approach 1: BFS
 Time: O(n)
 Space: O(n)

 Approach 2: DFS
 Time: O(n)
 Space: O(n)

*/

// Approach 1
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> todo;
        todo.push(root->left);
        todo.push(root->right);
        TreeNode* p = nullptr;
        TreeNode* q = nullptr;
        while (!todo.empty()) {
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

// Approach 2
class Solution {
public:
    bool Check(TreeNode* l, TreeNode* r)
    {
        if (!l && !r) return true;
        if (!l || !r) return false;
        if (l->val != r->val) return false;
        return Check(l->left, r->right) && Check(l->right, r->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return Check(root->left, root->right);
    }
};