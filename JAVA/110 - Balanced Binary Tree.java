/*
 110. Balanced Binary Tree (E)

 Approach 1 :
 Time: O(n)
 Space: O(n)

*/

/* Approach 1 */
class Solution {
    public boolean isBalanced(TreeNode root) {
        if (root == null) return true;
        return DFS(root) != -1;
    }
    
    public int DFS(TreeNode root) {
        if (root == null) return 0;
        int left = DFS(root.left);
        int right = DFS(root.right);
        if (left == -1 || right == -1 || Math.abs(left - right) > 1) {
            return -1;
        }
        return Math.max(left, right) + 1;
    }
}
