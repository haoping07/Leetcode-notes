/*
 154. Find Minimum in Rotated Sorted Array II (H)
 
 Approach 1 : BS
 Ref. 153
 The routine is similar to 153, but needs to handle the duplicate elements.
 If mid and end/start value are same, move the start/end ptr till different. 
 Time: O(logn)
 Space: O(1) 

*/

/* Approach 1 */
class Solution {
    public int findMin(int[] nums) {
        int start = 0, end = nums.length - 1;
        while (start < end - 1) {
            int mid = low + (end - start) / 2;
            if (nums[mid] == nums[end]) 
                end--;
            else if (nums[mid] < nums[end])
                end = mid;
            else
                start = mid;
        }
        return Math.min(nums[start], nums[end]);
    }
}
