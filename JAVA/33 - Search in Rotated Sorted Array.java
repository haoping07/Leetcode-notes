/*
 33. Search in Rotated Sorted Array (M)
 
 Approach 1 : 
 Scan the list, find the rotated range by comparing the mid and low value, then
 do the binary search based on the un-rotated range.
 Time: O(logn)
 Space: O(1)

*/

/* Approach 1 */
class Solution {
    public int search(int[] nums, int target) {
        if (nums.length == 0) return -1;
        int low = 0, high = nums.length - 1;
        
        while (low < high - 1) {
            int mid = low + (high - low) / 2;
            // If mid value is target, return mid
            if (target == nums[mid]) return mid;
            // If mid value is bigger than low value, this range is not rotated
            if (nums[low] < nums[mid]) {
                // Check if the target is between low and mid value
                if (target < nums[mid] && target >= nums[low])
                    high = mid;
                else
                    low = mid + 1;
            }
            // If mid value is smaller than low value, this range is rotated
            else {
                if (target > nums[mid] && target <= nums[high])
                    low = mid + 1;
                else 
                    high = mid;
            }
        }
        if (target == nums[low]) return low;
        if (target == nums[high]) return high;
        return -1;
    }
}
