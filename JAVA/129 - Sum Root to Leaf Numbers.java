/*
 129. Sum Root to Leaf Numbers (M)

 Approach 1 : DFS
 Time: O(n)
 Space: O(n)

*/

/* Approach 1 */
class Solution {
    public int sumNumbers(TreeNode root) {
        return DFS(root, 0);
    }
    
    public int DFS(TreeNode root, int prev) {
        if (root == null) return 0;
        int sum = prev * 10 + root.val;
        if (root.left == null && root.right == null) return sum;
        return DFS(root.left, sum) + DFS(root.right, sum);
    }
}