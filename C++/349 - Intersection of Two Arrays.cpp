/*
 349. Intersection of Two Arrays
 Easy
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        vector<int> result;
        for (int a : nums2)
        {
            if (set1.erase(a))
                result.push_back(a);
        }
        return result;
    }
};
