/*
 145. Binary Tree Postorder Traversal (H)

 Recursion
 O(n),O(n)

 DFS
 1.Traverse to the end of the left child.
 2.Peek parent, if parent->right exist and havn't been visited yet, move root 
 to parent->right and goto Step 1. If parent->right doesn't exist, push parent
 to result vector and mark it visited
 O(n),O(n)

*/

// Recursion
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        postorder(root, ret);
        return ret;
    }

    void postorder(TreeNode *root, vector<int> &ret)
    {
        if (!root) return;
        postorder(root->left, ret);
        postorder(root->right, ret);
        ret.push_back(root->val);
    }
};

// DFS
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        stack<TreeNode *> todo;
        TreeNode *visited = nullptr;
        while (!todo.empty() || root)
        {
            while (root)
            {
                todo.push(root);
                root = root->left;
            }
            TreeNode *peekNode = todo.top();
            if (peekNode->right && peekNode->right != visited)
            {
                root = peekNode->right;
            }
            else
            {
                ret.push_back(peekNode->val);
                todo.pop();
                visited = peekNode;
            }
        }
        return ret;
    }
};