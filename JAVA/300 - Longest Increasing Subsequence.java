/*
 300. Longest Increasing Subsequence (M)

 Approach 1 : DP
 dp[i] represents the longest increasing subsequence (include i) before index i.
 For each number, list all numbers which is smaller than it and record the 
 dp[i] = max(dp[j]) + 1 LIS.
 Time: O(n^2)
 Space: O(nums.length)

*/

/* Approach 1 */
class Solution {
    public int lengthOfLIS(int[] nums) {
        if (nums.length == 0) return 0;
        int[] dp = new int[nums.length];
        int max = 0;
        for (int i = 0; i < nums.length; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
                }
            }
            if (dp[i] > max) max = dp[i];
        }
        return max;
    }
}


