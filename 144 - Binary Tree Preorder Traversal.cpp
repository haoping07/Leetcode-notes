/*
 144. Binary Tree Preorder Traversal (M)

 Notes:
    Approach 1 : 
    Time: O(n)
    Space: O(n)

    Approach 2: Iteration
    Time: O(n)
    Space: O(n)

*/

// Approach 1 : Recursion
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return res;
    }

    void preorder(TreeNode* root)
    {
        if (!root) return;
        res.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }

private:
    vector<int> res;
};

// Approach 2 : Iteration 1
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> todo;
        vector<int> res;

        while (!todo.empty() || root)
        {
            if (root)
            {
                res.push_back(root->val);
                todo.push(root);
                root = root->left;
            }
            else
            {
                root = todo.top();
                todo.pop();
                root = root->right;
            }
        }
        return res;
    }
};

// Approach 2 : Iteration 2
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode*> todo;
        todo.push(root);

        while (!todo.empty())
        {
            root = todo.top();
            todo.pop();
            res.push_back(root->val);

            if (root->right)
                todo.push(root->right);
            if (root->left)
                todo.push(root->left);
        }

        return res;
    }
};