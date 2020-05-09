/*
 34. Find First and Last Position of Element in Sorted Array (M)
 
 Approach 1 : BS
 BS the list twice, one find the left boundary, one find the right boundary.
 Time: O(2logn)
 Space: O(1)

*/

/* Approach 1 */
class Solution {
    public int[] searchRange(int[] nums, int target) {
        if (nums.length == 0) return new int[] {-1, -1};
        int[] index = new int[2];
        int l = 0, r = nums.length - 1, m = 0;
        
        // Find left boundary
        while (l < r - 1) {
            m = l + (r - l) / 2;
            if (nums[m] >= target) r = m;
            else l = m;
        }
        
        if (nums[l] != target && nums[r] != target) 
            return new int[] {-1, -1};
        
        if (nums[l] == target) index[0] = l;
        else index[0] = r;
        
        // Find right boundary
        l = 0;
        r = nums.length - 1;
        while (l < r - 1) {
            m = l + (r - l) / 2;
            if (nums[m] <= target) l = m;
            else r = m;
        }
        
        // If there are only two nodes in the list, then handle the r node first
        if (nums[r] == target) index[1] = r;
        else index[1] = l;
        
        return index;
    }
}

