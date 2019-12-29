/*
 81. Search in Rotated Sorted Array II
 Medium
*/

// Approach 1
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

// Approach 2
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0) return false;
        int l = 0, r = size - 1;
        int m = 0;
        while (l <= r)
        {
            m = l + (r - l) / 2;
            if (target == nums[m])
                return true;
            if (nums[l] < nums[m])
            {
                if (target >= nums[l] && target < nums[m])
                    r = m - 1;
                else
                    l = m + 1;
            }
            else if (nums[l] > nums[m])
            {
                if (target > nums[m] && target <= nums[r])
                    l = m + 1;
                else
                    r = m - 1;
            }
            else
                l++;
        }
        return false;
    }
};