/*
 217. Contains Duplicate
 Easy

 Note:
    - O(n)
    Use unordered_set STL to store / find the visited number.
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> visited;
        for (int num : nums)
        {
            if (visited.find(num) != visited.end())
                return true;
            else
                visited.insert(num);
        }
        return false;
    }
};