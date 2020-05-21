/*
 144. Binary Tree Preorder Traversal (M)

 Approach 1: Recursion
 Time: O(n)
 Space: O(n)

 Approach 2: DFS
 Time: O(n)
 Space: O(n)

 Approach 3: BFS style DFS
 Time: O(n)
 Space: O(n)

*/

// Approach 1
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

// Approach 2
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> todo;
        vector<int> res;
        while (!todo.empty() || root) {
            if (root) {
                todo.push(root);
                res.push_back(root->val);
                root = root->left;
            }
            else {
                root = todo.top();
                todo.pop();
                root = root->right;
            }
        }
        return res;
    }
};

// Approach 3
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