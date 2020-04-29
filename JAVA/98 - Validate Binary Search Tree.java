/*
 98. Validate Binary Search Tree (M)

 Approach 1 : 
 Record the low and high bound in each recursion, check if the tree is validate
 by compare the current node to the low and high bound.
 Time: O(n)
 Space: O(n)

*/

/* Approach 1 */
class Solution {
    public boolean isValidBST(TreeNode root) {
        return Check(root, null, null);
    }
    
    public boolean Check(TreeNode root, TreeNode low, TreeNode high) {
        if (root == null) return true;
        if (low != null && root.val <= low.val) return false;
        if (high != null && root.val >= high.val) return false;
        return Check(root.left, low, root) && Check(root.right, root, high);
    }
}
