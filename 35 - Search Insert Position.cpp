/*
 35. Search Insert Position (E)
 
 Approach 1 : Binary Search
 Time: O(logn)
 Space: (1)

 MONO: Why move left to mid + 1 AND right to mid?
 Mid will be the left one if the list size is even, so left should move foward to
 not make loop endless (Keep edge movingin each round). Same thing to right, if 
 move right to mid - 1, this could occur endless loop if the list only have two 
 elements.

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
