/*
 1. Two Sum (E)

 Notes:
 Approach 1 : Hash
 Time: O(n)
 Space: O(n)

*/

// Approach 1 : Hash
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            if (hash.find(target - nums[i]) != hash.end())
            {
                res.push_back(hash[target - nums[i]]);
                res.push_back(i);
                return res;
            }
            hash[nums[i]] = i;
        }

        // Fake return 
        return res;
    }
};