/*
 90. Subsets II (M)

 Approach 1 : Backtracking
 [basketwangCoding - https://youtu.be/rtFHxiQAICA]
 1. Store the valid result
 2.1. Not choose, call helper(..false)
 * The duplicate occurs when two numbers are the same && the previous one isn't 
   chosen but the current one is chosen
 2.2. If chose = true OR the previous number is not same as the current one:
      1. Call helper(..true)
      else:
      // Duplicate occurs

 Time: O(n * 2^n), TWO options (choose/not choose) for n numbers
 Space: O(n * 2^n)

*/

/* Approach 1 : Backtracking */
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        sort(nums.begin(), nums.end());
        Helper(nums, res, sub, 0, true);
        return res;
    }

    void Helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& sub, int index, bool took)
    {
        if (index >= nums.size())
            res.push_back(sub);
        else
        {
            // Not choose
            Helper(nums, res, sub, index + 1, false);

            if (took || nums[index - 1] != nums[index])
            {
                // Choose
                sub.push_back(nums[index]);
                Helper(nums, res, sub, index + 1, true);
                sub.pop_back();
            }
        }
    }
};