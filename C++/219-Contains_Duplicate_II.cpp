/*
 219. Contains Duplicate II (E)

 Approach 1 :
 Time: O(n)
 Space: O(n)

*/

/* Approach 1 */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            if (hash.count(nums[i]) && i - hash[nums[i]] <= k)
                return true;
            hash[nums[i]] = i;
        }
        return false;
    }
};