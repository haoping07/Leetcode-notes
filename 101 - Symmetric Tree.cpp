/*
 101. Symmetric Tree (E)

  Notes:
     Ref. 100
*/

// BFS
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        TreeNode* left = nullptr, * right = nullptr;
        queue<TreeNode*> todo;
        todo.push(root->left);
        todo.push(root->right);
        while (!todo.empty())
        {
            left = todo.front();
            todo.pop();
            right = todo.front();
            todo.pop();

            if (left == nullptr && right == nullptr)
                continue;
            if (left == nullptr || right == nullptr)
                return false;
            if (left->val != right->val)
                return false;

            todo.push(left->left);
            todo.push(right->right);
            todo.push(left->right);
            todo.push(right->left);
        }
        return true;
    }
};

// Recursive
class Solution {
public:
    bool CheckMirror(TreeNode* left, TreeNode* right)
    {
        if (left == nullptr && right == nullptr)
            return true;
        if (left == nullptr || right == nullptr)
            return false;
        if (left->val != right->val)
            return false;
        return CheckMirror(left->left, right->right) && CheckMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return CheckMirror(root->left, root->right);
    }
};