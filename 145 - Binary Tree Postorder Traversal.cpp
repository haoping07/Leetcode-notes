/*
 145. Binary Tree Postorder Traversal (H)

 Notes:
 Approach 1 : Recursion
 Time: O(n)
 Space: O(n)

 Approach 2 : Iteration
 BFS iteration
 1. Traverse to the end of the left child.
 2. Peek parent
   2.1. If parent->right exist and havn't been visited yet, move root to parent->right and goto Step 1
        If parent->right doesn't exist, push parent to result vector and mark it visited
 Time: O(n)
 Space: O(n)

*/

// Approach 1 : Recursion
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        Postorder(root);
        return res;
    }

    void Postorder(TreeNode* root)
    {
        if (!root) return;
        Postorder(root->left);
        Postorder(root->right);
        res.push_back(root->val);
    }

private:
    vector<int> res;
};

// Approach 2 : Iteration
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> todo;
        TreeNode* visited = nullptr;

        while (!todo.empty() || root)
        {
            while (root)
            {
                todo.push(root);
                root = root->left;
            }

            TreeNode* peekNode = todo.top();
            if (peekNode->right && peekNode->right != visited)
                root = peekNode->right;
            else
            {
                res.push_back(peekNode->val);
                todo.pop();
                visited = peekNode;
            }
        }
        return res;
    }
};