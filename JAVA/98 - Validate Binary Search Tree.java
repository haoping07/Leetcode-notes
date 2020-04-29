/*
 98. Validate Binary Search Tree (M)

 Approach 1 : 
 Record the low and high boundary in each recursion, check if the tree is validate
 by comparing the current node to the low and high boundary.
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
