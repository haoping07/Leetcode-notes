/*
 26. Remove Duplicates from Sorted Array
 Easy
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int start = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[start] != nums[i])
            {
                start++;
                nums[start] = nums[i];
            }
        }
        return start + 1;
    }
};