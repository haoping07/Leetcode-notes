/*
 236. Lowest Common Ancestor of a Binary Tree (M)

 Approach 1 : Postorder traversal
 If find p or q, return p or q to parent.
 If find both p and q from parent's children, return that parent
 Time: O(n)
 Space: O(n)

*/

/* Approach 1 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) return null;
        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);
        
        if (root == p || root == q) return root;
        if (left != null && right != null) return root;
        
        return left == null ? right : left;
    }
}
