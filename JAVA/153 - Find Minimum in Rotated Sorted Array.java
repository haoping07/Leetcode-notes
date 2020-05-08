/*
 153. Find Minimum in Rotated Sorted Array (M)
 
 Approach 1 : BS
 If the list isn't rotated, just return the first element.
 If rotated, compare the mid and low value and BS it based on the rotation.
 Time: O(logn)
 Space: O(1) 

*/

/* Approach 1 */
class Solution {
    public int findMin(int[] nums) {
        int low = 0, high = nums.length - 1;
        
        // If the list isn't rotated, return the first element
        if (nums[high] >= nums[low]) return nums[low];
        
        while (low < high - 1) {
            int mid = low + (high - low) / 2;
            // If mid > low value, then the smallest is in right
            if (nums[mid] > nums[low])
                low = mid;
            // else, in left
            else
                high = mid;
        }
        return Math.min(nums[low], nums[high]);
    }
}
