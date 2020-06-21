/*
 235. Lowest Common Ancestor of a Binary Search Tree (E)
 
 Notes:
    Approach 1 :
    If two nodes' value is bigger than root, then the LCA must be in right subtree,
    else if smaller than root, then must in left subtree.
    Else, root is the LCA.
      T: O(log(n))
      S: O(log(n))
    
*/

// Approach 1 :
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pv = p->val;
        int qv = q->val;
        int rv = root->val;

        if (pv < rv && qv < rv)
            return lowestCommonAncestor(root->left, p, q);
        else if (pv > rv && qv > rv)
            return lowestCommonAncestor(root->right, p, q);
        else
            return root;
    }
};