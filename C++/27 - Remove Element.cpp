/*
 27. Remove Element (E)
 
 Approach 1 :
 Time: O(n)
 Space: O(1)

*/

/* Approach 1 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val)
                nums[slow++] = nums[i];
        }
        return slow;
    }
};