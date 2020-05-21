/*
 145. Binary Tree Postorder Traversal (H)

 Approach 1: Recursion
 Time: O(n)
 Space: O(n)

 Approach 2: DFS
 1. Traverse to the end of the left child.
 2. Peek parent
   2.1. If parent->right exist and havn't been visited yet, move root to parent->right and goto Step 1
        If parent->right doesn't exist, push parent to result vector and mark it visited
 Time: O(n)
 Space: O(n)

*/

// Approach 1
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }
    
    void postorder(TreeNode* root, vector<int>& res) {
        if (!root) return;
        postorder(root->left, res);
        postorder(root->right, res);
        res.push_back(root->val);
    }
};

// Approach 2
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> todo;
        TreeNode* visited = nullptr;
        while (!todo.empty() || root) {
            if (root) {
                todo.push(root);
                root = root->left;
            }
            else {
                TreeNode* peekNode = todo.top();
                if (peekNode->right && peekNode->right != visited) {
                    root = peekNode->right;
                }
                else {
                    res.push_back(peekNode->val);
                    todo.pop();
                    visited = peekNode;
                }
            }
        }
        return res;
    }
};