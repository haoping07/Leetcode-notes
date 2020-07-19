/*
 94. Binary Tree Inorder Traversal (M)
 
 Recursion
 O(n),O(n)

 DFS
 O(n),O(n)

*/

// Recursion
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        Inorder(root, ret);
        return ret;
    }
    
    void Inorder(TreeNode* root, vector<int>& ret) {
        if (!root) return;
        Inorder(root->left, ret);
        ret.push_back(root->val);
        Inorder(root->right, ret);
    }
};

// DFS
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> todo;
        while (!todo.empty() || root) {
            while (root) {
                todo.push(root);
                root = root->left;
            }
            root = todo.top();
            todo.pop();
            ret.push_back(root->val);
            root = root->right;
        }
        return ret;
    }
};