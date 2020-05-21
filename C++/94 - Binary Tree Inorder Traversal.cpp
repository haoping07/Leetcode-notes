/*
 94. Binary Tree Inorder Traversal (M)
 
 Approach 1: Recursion
 Time: O(n)
 Space: O(n)

 Approach 2: DFS
 Time: O(n)
 Space: O(n)

*/

// Approach 1
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
    
    void inorder(TreeNode* root, vector<int>& res) {
        if (!root) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
};

// Approach 2
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> todo;
        while (!todo.empty() || root) {
            if (root) {
                todo.push(root);
                root = root->left;
            }
            else {
                root = todo.top();
                todo.pop();
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};