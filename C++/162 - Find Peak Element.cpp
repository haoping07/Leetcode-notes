/*
 162. Find Peak Element
 Medium
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, m = 0;
        while (l + 1 < r)
        {
            m = l + (r - l) / 2;
            if (nums[m] > nums[m - 1] && nums[m] > nums[m + 1])
                return m;
            else if (nums[m] > nums[m - 1])
                l = m + 1;
            else if (nums[m] < nums[m - 1])
                r = m;
        }
 
        return nums[l] > nums[r] ? l : r;
    }
};
