/*
 144. Binary Tree Preorder Traversal (M)

 Recursion
 O(n),O(n)

 DFS
 O(n),O(n)

 BFS style DFS
 O(n),O(n)

*/

// Recursion
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        DFS(root, res);
        return res;
    }
    
    void DFS(TreeNode* root, vector<int>& res) {
        if (!root) return;
        res.push_back(root->val);
        DFS(root->left, res);
        DFS(root->right, res);
    }
};

// DFS
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> todo;
        while (!todo.empty() || root) {
            while (root) {
                ret.push_back(root->val);
                todo.push(root);
                root = root->left;
            }
            root = todo.top();
            todo.pop();
            root = root->right;
        }
        return ret;
    }
};

// BFS style DFS
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode*> todo;
        todo.push(root);
        while (!todo.empty()) {
            root = todo.top();
            todo.pop();
            res.push_back(root->val);
            if (root->right) todo.push(root->right);
            if (root->left) todo.push(root->left);
        }
        return res;
    }
};