/*
 26. Remove Duplicates from Sorted Array (E)
 
 Approach 1 :
 Time: O(n)
 Space: O(1)

*/

/* Approach 1 */
class Solution {
    public int removeDuplicates(int[] nums) {
        int index = 0;
        for (int i = 1; i < nums.length; i++) {
            if (nums[index] != nums[i]) {
                nums[++index] = nums[i];
            }
        }
        return index + 1;
    }
}