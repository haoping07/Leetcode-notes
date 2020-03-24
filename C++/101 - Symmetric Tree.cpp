/*
 101. Symmetric Tree (E)

 Ref. 100

 Approach 1 : BFS
 Time: O(n)
 Space: O(n)

 Approach 2 : DFS
 Time: O(n)
 Space: O(n)

*/

/* Approach 1 : BFS */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> todo;
        todo.push(root->left);
        todo.push(root->right);
        TreeNode* left = nullptr;
        TreeNode* right = nullptr;
        while (!todo.empty())
        {
            left = todo.front();
            todo.pop();
            right = todo.front();
            todo.pop();

            if (!left && !right) continue;
            if (!left || !right) return false;
            if (left->val != right->val) return false;

            todo.push(left->left);
            todo.push(right->right);
            todo.push(left->right);
            todo.push(right->left);
        }
        return true;
    }
};

/* Approach 2 : DFS */
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