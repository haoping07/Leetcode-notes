/*
 80. Remove Duplicates from Sorted Array II (M)
 
 Approach 1:
 Ref.26
 Time: O(n)
 Space: O(1)

*/

// Approach 1
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int index = 0, c = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[index]) {
                nums[++index] = nums[i];
                c = 1;
            }
            else {
                if (c < 2) {
                    nums[++index] = nums[i];
                    c++;
                }
            }
        }
        return index + 1;
    }
};