/*
 33. Search in Rotated Sorted Array
 Medium
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1;
        int l = 0, r = nums.size() - 1, m = 0;
        while (l + 1 < r)
        {
            m = l + (r - l) / 2;
            if (target == nums[m])
                return m;
            if (nums[l] < nums[m])
            {
                if (target < nums[m] && target >= nums[l])
                    r = m;
                else
                    l = m + 1;
            }
            else
            {
                if (target > nums[m] && target <= nums[r])
                    l = m + 1;
                else
                    r = m;
            }
        }
 
        if (target == nums[l])
            return l;
        if (target == nums[r])
            return r;
        return -1;
    }
};
