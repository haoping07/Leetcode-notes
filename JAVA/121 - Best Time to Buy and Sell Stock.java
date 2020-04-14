/*
 121. Best Time to Buy and Sell Stock (E)
 
 Approach 1 : DP
 Iterate the array, make minp to record the smallest element, maxp to record 
 the most profit (which is current element - minp). When iteration is over,
 maxp is the best profit can achhieve.
 Time: O(n)
 Space: O(1)

*/

/* Approach 1 */
class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length == 0 || prices.length == 1) return 0;
        int maxp = 0;
        int minp = prices[0];
        for (int i = 1; i < prices.length; i++) {
            maxp = Math.max(maxp, prices[i] - minp);
            minp = Math.min(minp, prices[i]);
        }
        return maxp;
    }
}