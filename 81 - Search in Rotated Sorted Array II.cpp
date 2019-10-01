/*
 81. Search in Rotated Sorted Array II
 Medium
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return false;
        int l = 0, r = nums.size() - 1, m = 0;
        while (l + 1 < r)
        {
            int m = l + (r - l) / 2;
            if (target == nums[m])
                return true;
            if (nums[m] == nums[l] && nums[m] == nums[r])
            {
                l++;
                r--;
            }
            else if (nums[m] >= nums[l])
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
        if (nums[l] == target || nums[r] == target)
            return true;
        return false;
    }
};
