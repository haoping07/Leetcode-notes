/*
 350. Intersection of Two Arrays II
 Easy
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int>::iterator it1 = nums1.begin(), it2 = nums2.begin();
        vector<int> result;
        while (it1 != nums1.end() && it2 != nums2.end())
        {
            if (*it1 > *it2)
                it2++;
            else if (*it1 < *it2)
                it1++;
            else
            {
                result.push_back(*it1);
                it1++;
                it2++;
            }
        }
        return result;
    }
};
