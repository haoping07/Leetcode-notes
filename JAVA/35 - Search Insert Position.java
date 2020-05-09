/*
 35. Search Insert Position (E)
 
 Approach 1 : Binary Search
 Time: O(logn)
 Space: O(1)

 Think: How do I know when to mid - 1 or mid + 1
 Try the two nodes case and decide based on the problem.
 
*/

/* Approach 1 */
class Solution {
    public int searchInsert(int[] nums, int target) {
        int low = 0, high = nums.length - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (target == nums[mid]) 
                return mid;
            else if (target < nums[mid])
                high = mid;
            else
                low = mid + 1;
        }
        return target <= nums[low] ? low : low + 1;
    }
}
