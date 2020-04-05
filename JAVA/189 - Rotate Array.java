/*
 189. Rotate Array (E)

 Approach 1 : Exchange
 Exchange one by one
 Time: O(n)
 Space: O(1)

*/

/* Approach 1 */
class Solution {
    public void rotate(int[] nums, int k) {
        k %= nums.length;
        int c = 0;
        for (int i = 0; i < nums.length; i++) {
            int startId = i, startVal = nums[i];
            do {
                int newPos = (startId + k) % nums.length;
                int tmp = nums[newPos];
                nums[newPos] = startVal;
                startId = newPos;
                startVal = tmp;
                c++;
            } while (startId != i);
            if (c == nums.length) return;
        }
    }
}