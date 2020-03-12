/*
 27. Remove Element (E)
 
 Approach 1 :
 Time: O(n)
 Space: O(1)

*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int start = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (val != nums[i])
                nums[start++] = nums[i];
        }
        return start;
    }
};