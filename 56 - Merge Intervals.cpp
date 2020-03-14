/*
 56. Merge Intervals (M)

 Approach 1 :
 Time: O(nlogn), sort() is nlogn
 Space: O(n)

*/

/* Approach 1 */
class Solution {
public:
    class comp
    {
    public:
        bool operator()(const vector<int>& a, const vector<int>& b)
        {
            return a[0] < b[0];
        }
    };

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp());
        vector<vector<int>> res;
        for (const vector<int>& interval : intervals)
        {
            if (res.empty() || res.back()[1] < interval[0])
                res.push_back(interval);
            else
                res.back()[1] = max(res.back()[1], interval[1]);
        }
        return res;
    }
};
