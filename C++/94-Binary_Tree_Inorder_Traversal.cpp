/*
 94. Binary Tree Inorder Traversal (M)
 
 A1: Recursion
 Time: O(n)
 Space: O(n)

 A2: DFS
 Time: O(n)
 Space: O(n)

*/

// A1
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

// A2
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