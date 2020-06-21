/*
 374. Guess Number Higher or Lower
 Easy
*/

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n, m = 0;
        while (l <= r)
        {
            m = l + (r - l) / 2;
            int f = guess(m);
            if (f == 0)
                return m;
            if (f == 1)
                l = m + 1;
            else
                r = m;
        }
        return -1;
    }
};
