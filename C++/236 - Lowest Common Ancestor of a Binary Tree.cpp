
/*
 236. Lowest Common Ancestor of a Binary Tree (M)

 Notes:
 Approach 1 : Postorder traversal
 Use Postorder traversal. If found, return to parent. 
 Time: O(n), traverse all nodes
 Space: O(n)

*/

// Approach 1 : Postorder traversal
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (root == p || root == q)
            return root;

        if (left && right)
            return root;

        return left == nullptr ? right : left;
    }
};