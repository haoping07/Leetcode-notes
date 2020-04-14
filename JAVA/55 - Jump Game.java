/*
 55. Jump Game (M)

 Approach 1 : Backtracking   
 Scan the list from end to head. If the current scanned element is 0, it means
 the next scanned element will need to have one additional step to pass this 
 element, or it will stuck in here. If scan is over but still need steps to pay
 off, then it is impossible to reach the end.
 Time: O(n)
 Space: O(1)

 Approach 2 : DP
 Time: O(n)
 Space: O(nums.length)

*/

/* Approach 1 */
class Solution {
    public boolean canJump(int[] nums) {
        int skip = 0;
        for (int i = nums.length - 2; i >= 0; i--) {
            if (nums[i] - skip <= 0) skip++;
            else skip = 0;
        }
        return skip == 0;
    }
}

/* Approach 2 */
class Solution {
    public boolean canJump(int[] nums) {
        int[] dp = new int[nums.length];
        for (int i = 1; i < nums.length; i++) {
            dp[i] = Math.max(dp[i - 1], nums[i - 1]) - 1;
            if (dp[i] < 0) return false;
        }
        return true;        
    }
}