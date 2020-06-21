/*
 26. Remove Duplicates from Sorted Array (E)

 Approach 1: 
 Ref.27
 Time: O(n)
 Space: O(1)

*/

// Approach 1
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int index = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[index]) nums[++index] = nums[i];
        }
        return index + 1;
    }
};