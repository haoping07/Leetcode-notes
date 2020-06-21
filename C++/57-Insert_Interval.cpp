/*
 57. Insert Interval (H)

 Approach 1 : Insert and merge
 Time: O(n)
 Space: O(n)

 Approach 2 : Left + overlapped + Right
 Time: O(n)
 Space: O(n)

*/

/* Approach 1 */
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // Insert new interval to appropriate position
        vector<vector<int>>::iterator it = intervals.begin();
        while (it != intervals.end() && (*it)[0] < newInterval[0])
            it++;
        intervals.insert(it, newInterval);

        // Merge the interval
        vector<vector<int>> res;
        for (const vector<int>& interval : intervals)
        {

            if (res.empty() || interval[0] > res.back()[1])
                res.push_back(interval);
            else
                res.back()[1] = max(res.back()[1], interval[1]);
        }
        return res;
    }
};


/* Approach 2 */
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> left;
        vector<vector<int>> right;
        int start = newInterval[0], end = newInterval[1];
        for (const vector<int>& interval : intervals)
        {
            // Build left
            if (interval[1] < start)
                left.push_back(interval);
            // Build right
            else if (interval[0] > end)
                right.push_back(interval);
            // Overlapping
            else
            {
                start = min(interval[0], start);
                end = max(interval[1], end);
            }
        }

        // Build output vector
        // Build left
        vector<vector<int>> res(move(left));
        // Build overlapping
        res.push_back({ start, end });
        // Build right
        res.insert(res.end(), right.begin(), right.end());
        return res;
    }
};