/*
 26. Remove Duplicates from Sorted Array (E)

 Notes:
    T: O(n)
    S: O(1)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int start = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[start] != nums[i])
                nums[++start] = nums[i];
        }
        return start + 1;
    }
};