/*
 278. First Bad Version (E)

 Approach 1 : Binary Search
 Time: O(logn)
 Space: O(1)

 Think: Why move left to mid + 1 AND right to mid?
 Mid will be the left one if the list size is even, so left should move foward to
 not make loop endless (Keep edge movingin each round). If move right to mid - 1,
 we can't get the answer if the list only have two elements.

*/

/* Approach 1 */
public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int low = 1, high = n;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (isBadVersion(mid)) high = mid;
            else low = mid + 1;
        }
        return low;
    }
}
