/*
 230. Kth Smallest Element in a BST (M)

 Notes:
 Approach 1 : DFS (Inorder) to vector
 DFS (inorder) to a vector, the next() will return the vector one by one.
 Time: O(1)
 Space: O(n)

 Follow up : DFS to stack
 Time: O(n)
 Space: O(n)

*/


/* Approach 1 : */
class Solution {
private:
    vector<int> nodes;
public:
    int kthSmallest(TreeNode* root, int k) {
        DFS(root);
        return nodes[k - 1];
    }

    void DFS(TreeNode* root)
    {
        if (!root) return;
        DFS(root->left);
        nodes.push_back(root->val);
        DFS(root->right);
    }
};


/* Follow up */
class Solution {
private:
    stack<TreeNode*> nodes;
public:
    int kthSmallest(TreeNode* root, int k) {
        while (!nodes.empty() || root)
        {
            while (root)
            {
                nodes.push(root);
                root = root->left;
            }

            TreeNode* node = nodes.top();
            nodes.pop();

            if (k == 1)
                return node->val;
            else
            {
                root = node->right;
                k--;
            }
        }
        return -1;
    }
};