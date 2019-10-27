/*
 55. Jump Game (Medium)

 Notes:
    Greedy algorithm - O(n)
    Scan the list from end to begin. If the list[i] value is "0", the list[i - 1] will need to have addtional step
    to skip this element. If reach the first element and still need steps to pay off additional steps, then it is 
    impossible to reach the end.
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int gap = 0;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] - gap <= 0)
                gap++;
            else
                gap = 0;
        }
        return gap == 0;
    }
};