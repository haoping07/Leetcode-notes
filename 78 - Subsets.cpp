/*
 78. Subsets (M)

 Approach 1 : Combinations (DFS + Backtracking)
 Time: O(n * 2^n), push to TWO (res & sub) vectors for n numbers
 Space: O(n * 2^n)

 Approach 2 : DFS + Backtracking
 [basketwangCoding - https://youtu.be/rtFHxiQAICA]
 1. Store the valid result
 2.1. Not choose, call helper()
 2.2. Choose, call helper()
 Time: O(n * 2^n), TWO options (choose/not choose) for n numbers
 Space: O(n * 2^n)

 Follow up: 
 90 - Subsets II

*/

/* Approach 1 : Combinations (DFS + Backtracking) */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        helper(nums, res, sub, 0);
        return res;
    }

    void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& sub, int index)
    {
        res.push_back(sub);
        for (int i = index; i < nums.size(); i++)
        {
            sub.push_back(nums[i]);
            helper(nums, res, sub, i + 1);
            sub.pop_back();
        }
    }
};


/* Approach 2 : Backtracking (Choose / Not choose) */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        helper(nums, res, sub, 0);
        return res;
    }

    void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& sub, int index)
    {
        if (index >= nums.size())
            res.push_back(sub);
        else
        {
            helper(nums, res, sub, index + 1);
            sub.push_back(nums[index]);
            helper(nums, res, sub, index + 1);
            sub.pop_back();
        }
    }
};