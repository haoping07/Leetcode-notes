/*
 374. Guess Number Higher or Lower (E)
 
 Approach 1 : BS
 Think: Why edge can be m + 1 / m - 1?
 THe answer must be in the list. Always think about the case with least nodes
 based on the problem. 
 Time: O(logn)
 Space: O(1)

*/

/* Approach 1 */
public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int l = 1, r = n;
        while (l < n) {
            int m = l + (r - l) / 2;
            if (guess(m) == 0)
                return m;
            else if (guess(m) == 1)
                l = m + 1;
            else
                r = m - 1;
        }
        return l;
    }
}