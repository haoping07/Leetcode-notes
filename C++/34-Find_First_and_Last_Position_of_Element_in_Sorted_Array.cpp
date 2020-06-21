/*
 34. Find First and Last Position of Element in Sorted Array
 Medium
*/

class Solution {
public:
    void func(vector<int>& nums, int l, int r, int target, int& ans_left, int& ans_right)
    {
        int index = -1, left = l, right = r;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] == target)
            {
                index = m;
                break;
            }
 
            if (nums[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }
 
        if (index == -1)
            return;
 
        if (index < ans_left)
            ans_left = index;
        if (index > ans_right)
            ans_right = index;
 
        func(nums, left, index - 1, target, ans_left, ans_right);
        func(nums, index + 1, right, target, ans_left, ans_right);
    }
 
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = nums.size(), r = -1;
        func(nums, 0, nums.size() - 1, target, l, r);
        if (l > r)
            return {-1, -1};
        return {l, r};
    }
};
