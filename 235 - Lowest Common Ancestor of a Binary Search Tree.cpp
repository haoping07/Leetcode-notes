/*
 235. Lowest Common Ancestor of a Binary Search Tree
 Easy
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int rval = root->val;
        int pval = p->val;
        int qval = q->val;

        if (pval > rval&& qval > rval)
            return lowestCommonAncestor(root->right, p, q);
        else if (pval < rval && qval < rval)
            return lowestCommonAncestor(root->left, p, q);
        else
            return root;
    }
};