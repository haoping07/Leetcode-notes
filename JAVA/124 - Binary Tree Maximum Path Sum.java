/*
 124. Binary Tree Maximum Path Sum (H)

 Approach 1 : 
 Four possibilities:
 1. Take only left + root.val
 2. Take only right + root.val
 3. Take only root.val
 4. Take both + root.val and STOP
 , then record the max
 Time: O(n)
 Space: O(n)

*/

/* Approach 1 */
class Solution {
    int maxSum = Integer.MIN_VALUE;
    public int maxPathSum(TreeNode root) {
        DFS(root);
        return maxSum;
    }
    
    public int DFS(TreeNode root) {
        if (root == null) return 0;
        int left = DFS(root.left);
        int right = DFS(root.right);
        
        // Take one vs no take vs take both
        int takeOne = Math.max(Math.max(left, right) + root.val, root.val);
        maxSum = Math.max(maxSum, Math.max(takeOne, left + right + root.val));
        
        return takeOne;
    }
}


