/*
 144. Binary Tree Preorder Traversal (Medium)

 Notes:
    Tree traverse - BFS or DFS. Use DFS here o(n)
    Approach 1: Trasverse left child till the end, then check the right child
    Approach 2: In each iteration, push current node's val to result, then check whether if 
    left / right child exist. If yes, push the right child then left child into the stack

    * If you want to address the current node in current round, use Approach 1
    * If you want to address the previous node in current round, use Approach 2
*/

// Approach 1
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

// Approach 2
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