/*
 108. Convert Sorted Array to Binary Search Tree (E)
 
 Approach 1 : Recursion + partition
 Time: O(n)
 Space: O(n)

*/

/* Approach 1 */
class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
        return BuildTree(nums, 0, nums.length - 1);
    }
    
    public TreeNode BuildTree(int[] nums, int low, int high) {
        if (low > high) return null;
        int mid = low + (high - low) / 2;
        
        TreeNode newNode = new TreeNode(nums[mid]);
        newNode.left = BuildTree(nums, low, mid - 1);
        newNode.right = BuildTree(nums, mid + 1, high);
        
        return newNode;
    }
}

