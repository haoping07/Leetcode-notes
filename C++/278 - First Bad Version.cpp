/*
 278. First Bad Version (E)
 
 Approach 1 : Binary Search
 Time: O(logn)
 Space: O(1)

 MONO: Why move left to mid + 1 AND right to mid?
 Mid will be the left one if the list size is even, so left should move foward to
 not make loop endless (Keep edge movingin each round). Same thing to right, if
 move right to mid - 1, this could occur endless loop if the list only have two
 elements.

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
