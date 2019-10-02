/*
 189. Rotate Array
 Easy

 How: 
 Rotate three time
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.begin() + nums.size() - k);
        reverse(nums.begin() + nums.size() - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};