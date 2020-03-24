/*
 35. Search Insert Position (E)
 
 Approach 1 : Binary Search
 Time: O(logn)
 Space: (1)

*/

/* Approach 1 : Binary Search */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (target == nums[m])
                return m;
            else if (target > nums[m])
                l = m + 1;
            else
                r = m;
        }
        return target > nums[l] ? l + 1 : l;
    }
};
