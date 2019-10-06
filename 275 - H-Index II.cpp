/*
 275. H-Index II
 Medium
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        int l = 0, r = size - 1, mid = 0, h = 0, ans = 0;
        while (l <= r)
        {
            mid = l + (r - l) / 2;

            // number of the element in the right side of mid
            h = size - mid;

            if (citations[mid] >= h)
            {
                ans = max(ans, h);
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};