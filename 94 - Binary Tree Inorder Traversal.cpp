/*
 94. Binary Tree Inorder Traversal (Medium)
 
 Notes:
    Tree trasverse - BFS, DFS. Use DFS here. O(n)
    Traverse and push left child to stack until the end. Pop and visit the top node in stack,
    if the node have right child, push it into stack. 
*/


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> todo;
        while (!todo.empty() || root)
        {
            if (root)
            {
                todo.push(root);
                root = root->left;
            }
            else
            {
                root = todo.top();
                todo.pop();
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};