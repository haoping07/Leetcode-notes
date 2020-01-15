/*
 94. Binary Tree Inorder Traversal (Medium)
 
 Notes:
    Tree trasverse - BFS, DFS. Use DFS here. O(n)
    Traverse and push left child to stack until the end. Pop and visit the top node in stack,
    if the node have right child, push it into stack. 

    * Ref 144: The Approach 2 in Q.144 can be used here, but it will need to track the visited node to know when
               to push the node value to the result vector.
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