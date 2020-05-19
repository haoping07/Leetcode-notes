/*
 27. Remove Element (E)
 
 Approach 1 :
 Set index to the next position of lastest updated array. Loop the array from 
 head, if the element is not equal to val, update to the index value then 
 increment 1.
 Time: O(n)
 Space: O(1)

*/

/* Approach 1 */
class Solution {
    public int removeElement(int[] nums, int val) {
        int slow = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != val) nums[slow++] = nums[i];
        }
        return slow;
    }
}