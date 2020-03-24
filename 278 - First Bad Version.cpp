/*
 278. First Bad Version (E)
 
 Approach 1 : Binary Search
 Time: O(logn)
 Space: O(1)

*/

/* Approach 1 : Binary Search */
class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n, m = 0;
        while (l < r)
        {
            m = l + (r - l) / 2;
            if (isBadVersion(m))
                // Because m is always the left one if the list size is even
                r = m;
            else 
                l = m + 1;
        }
        return l;
    }
};
