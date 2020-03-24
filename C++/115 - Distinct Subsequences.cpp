/*
 115. Distinct Subsequences (H)

 Notes:
 Approach 1 : DP
 Two-dimension DP, See HuaHua(https://www.youtube.com/watch?v=mPqqXh8XvWY)
 Time: O(n^2)
 Space: O(n^2)

*/

// Approach 1 : DP
class Solution {
public:
    int numDistinct(string s, string t) {
        int ls = s.size();
        int lt = t.size();
        vector<vector<unsigned int>> dp(lt + 1, vector<unsigned int>(ls + 1));
        fill(begin(dp[0]), end(dp[0]), 1);
        for (int i = 1; i <= lt; i++)
        {
            for (int j = 1; j <= ls; j++)
                dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0);
        }
        return dp[lt][ls];
    }
};