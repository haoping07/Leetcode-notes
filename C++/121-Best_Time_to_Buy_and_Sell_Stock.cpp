/*
 121. Best Time to Buy and Sell Stock (Easy)
 
 Notes:
    DP - O(n)
    Two parts:
        1. Use a variable "maxp" to record profit, keep the largest value between previous max profit and
           (current price - current minimum price("minp" from second part) )
        2. Use a variable "minp" to record current smallest price, keep the smallest price between 
           previous and current price.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty() || prices.size() == 1)
            return 0;

        int maxp = 0;
        int minp = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            maxp = max(maxp, prices[i] - minp);
            minp = min(minp, prices[i]);
        }
        return maxp;
    }
};