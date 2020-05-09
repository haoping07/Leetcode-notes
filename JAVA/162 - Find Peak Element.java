/*
 162. Find Peak Element (M)

 Approach 1 : BS
 If the list trend is going up, then move the edge towrd the up way, else, down
 way. If don't want to add precondition like if (nums.length == 0)... leave two
 nodes after loop is a must.
 Time: O(logn)
 Space: O(1)

*/

/* Approach 1 */
class Solution {
    public int findPeakElement(int[] nums) {
        int l = 0, r = nums.length - 1;
        while (l < r - 1) {
            int m = l + (r - l) / 2;
            if (nums[m] > nums[m - 1] && nums[m] > nums[m + 1])
                return m;
            else if (nums[m] > nums[m - 1])
                // It is ok to just l = m
                l = m + 1;
            else
                // It is ok to just r = m
                r = m - 1;
        }
        return nums[l] > nums[r] ? l : r;
    }
}

