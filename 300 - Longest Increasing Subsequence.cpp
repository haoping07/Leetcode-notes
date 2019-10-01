/*
 300. Longest Increasing Subsequence
 Medium
*/

// O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int f[nums.size()];
        int max = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            f[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                    f[i] = f[i] > f[j] + 1 ? f[i] : f[j] + 1;
            }
 
            if (f[i] > max)
                max = f[i];
        }
        return max;
    }
};

// O(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for (int i = 0; i < nums.size(); i++)
        {
            int left = 0;
            int right = dp.size();
            while (left < right)
            {
                int mid = left + (right - left) / 2;
                if (dp[mid] < nums[i])
                    left = mid + 1;
                else
                    right = mid;
            }
 
            if (right >= dp.size())
                dp.push_back(nums[i]);
            else
                dp[right] = nums[i];
        }
        return dp.size();
    }
};
