/*
 94. Binary Tree Inorder Traversal (M)
 
 Notes:
 Approach 1 :
 Recursion
 Time: O(n)
 Space: O(n)

 Approach 2 :
 Iteration
 Time: O(n)
 Space: O(n)

 * Ref 144: The Approach 2 in Q.144 can be used here, but it will need to track the visited node to know when
            to push the node value to the result vector.
*/

// Approach 1 : Recursion
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        Inorder(root);
        return res;
    }

    void Inorder(TreeNode* root)
    {
        if (!root) return;
        Inorder(root->left);
        res.push_back(root->val);
        Inorder(root->right);
    }

private:
    vector<int> res;
};

// Approach 2 : Iteration
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