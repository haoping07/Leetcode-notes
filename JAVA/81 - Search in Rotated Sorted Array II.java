/*
 81. Search in Rotated Sorted Array II (M)

 Approach 1 :
 Ref.33
 When low value equal to high value, low++
 Time: O(logn)
 Space: O(1)

*/

/* Approach 1 */
class Solution {
    public boolean search(int[] nums, int target) {
        if (nums.length == 0) return false;
        
        int low = 0, high = nums.length - 1;

        while (low < high - 1) {
            int mid = low + (high - low) / 2;
            
            if (target == nums[mid]) 
                return true;

            // When low value is equal to high value, move low one step foward
            if (nums[low] == nums[high]) low++;
            else if (nums[low] <= nums[mid]) {
                if (target < nums[mid] && target >= nums[low]) high = mid;
                else low = mid + 1;
            }
            else {
                if (target > nums[mid] && target <= nums[high]) low = mid + 1;
                else high = mid;
            }
        }
        
        if (target == nums[low] || target == nums[high]) return true;
        
        return false;
    }
}
