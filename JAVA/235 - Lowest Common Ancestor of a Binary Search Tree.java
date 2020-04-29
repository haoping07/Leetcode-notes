/*
 235. Lowest Common Ancestor of a Binary Search Tree (E)

 Approach 1 : 
 If q val and p val is smaller than root val, check root.left
 Else if q val and p val is bigger than root val, check root.right
 Else, root is the LCA
 Time: O(n)
 Space: O(n)

*/

/* Approach 1 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        int pval = p.val;
        int qval = q.val;
        int rval = root.val;
        
        if (pval < rval && qval < rval) 
            return lowestCommonAncestor(root.left, p, q);
        else if (pval > rval && qval > rval) 
            return lowestCommonAncestor(root.right, p, q);
        else return root;
    }
}