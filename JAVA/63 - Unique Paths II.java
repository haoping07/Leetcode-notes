
/*
 63. Unique Paths II (M)

 Approach 1 :
 Skip the position if have obstacle
 Time: O(mn)
 Space: O(mn)

*/

/* Approach 1 */
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        int[][] dp = new int[m][n];
        
        // Initialize the dp
        if (obstacleGrid[0][0] == 0) 
            dp[0][0] = 1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Skip the position if there have obstacle
                if (obstacleGrid[i][j] == 1) continue;
                if (i > 0) dp[i][j] += dp[i - 1][j];
                if (j > 0) dp[i][j] += dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
}
