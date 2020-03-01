/*
 80. Remove Duplicates from Sorted Array II (M)
 
 Notes:
 Approach 1 :
 Time: O(n)
 Space: O(1)

*/

// Approach 1 :
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        int slow = 0;
        int c = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[slow] != nums[i])
            {
                nums[++slow] = nums[i];
                c = 1;
            }
            else
            {
                if (c < 2)
                {
                    nums[++slow] = nums[i];
                    c++;
                }
            }
        }
        return slow + 1;
    }
};