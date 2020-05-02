/*
 70. Climbing Stairs (E)

 Approach 1 :
 There are two ways to land on the current stair from previous round: 1 step and
 2 steps. The total possibilities to achieve n stairs is the possibilities of 
 (n - 1) plus (n - 2).
 Time: O(n)
 Space: O(n)

*/

/* Approach 1 */
class Solution {
    public int climbStairs(int n) {
        int[] dp = new int[n + 1];
        
        // Initialize the step
        // 2 step from start
        dp[0] = 1;
        // 1 step from start
        dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            // One step + two step to i 
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dp[n];        
    }
}