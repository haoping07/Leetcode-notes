/*
 122. Best Time to Buy and Sell Stock II (Easy)
 
 Notes:
    Greedy Algo - O(n)
    Once there is a chance to earn money, sell the stock immediately
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
                profit += prices[i] - prices[i - 1];
        }
        return profit;
    }
};