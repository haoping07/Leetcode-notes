/*
 153. Find Minimum in Rotated Sorted Array
 Medium
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        return findMin(nums, l, r);
    }
 
    int findMin(vector<int>& nums, int l, int r)
    {
        if (l + 1 >= r)
            return min(nums[l], nums[r]);
 
        if (nums[l] < nums[r])
            return nums[l];
 
        int m = l + (r - l) / 2;
 
        return min(findMin(nums, l, m - 1), findMin(nums, m, r));
    }
};
