/*
 104. Maximum Depth of Binary Tree (E)

 Approach 1 :
 Time: O(n)
 Space: O(n)

*/

/* Approach 1 */
class Solution {
    public int maxDepth(TreeNode root) {
        if (root == null) return 0;
        return Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
    }
}