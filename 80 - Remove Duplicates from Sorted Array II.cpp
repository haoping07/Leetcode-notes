/*
 80. Remove Duplicates from Sorted Array II
 Medium
*/

// Pay attention to overflow!
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int prev = nums[0], i = -1, dup = -1;
        for (auto n : nums)
        {
            if (prev == n)
            {
                if (dup == -1) 
                    dup = 0;
                else 
                    dup++;
            }
            else
            {
                dup = 0;
                prev = n;
            }
            if (dup < 2)
            {
                i++;
                nums[i] = n;
            }
        }
        return i + 1;
    }
};