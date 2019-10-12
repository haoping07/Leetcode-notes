/*
 283. Move Zeroes (Easy)

 How:
    Two pointers - O(n)
    Make two pointers, left and right, point to the first element of given array. While right < array.size(), do: 
    if the right's value is not 0, then swap(left, right), move left & right forward, if 0, move right forward
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 0;
        while (right < nums.size())
        {
            if (nums[right])
            {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};

