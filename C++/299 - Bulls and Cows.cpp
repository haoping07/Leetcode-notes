/*
 299. Bulls and Cows (E)

 Approach 1 :
 Use array and two For-loop.
 1. Iterates secret and guess at the same time. If two letter are the same, bull++.
    Counts the appear of letter and stores to the array by its ASCII as key. 
 2. Iterates two arrays at the same time, take the minumum in each and adds to the cow;
 * The amount of cow is all exist numbers (whether the position is wrong) - position is correct (bull)
 Time: O(n)
 Space: O(1)

*/

class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0, cow = 0;
        int s[10] = { 0 }, g[10] = { 0 };
        for (int i = 0; i < secret.size(); i++) {
            int x = secret[i] - '0';
            int y = guess[i] - '0';
            if (x == y) bull++;
            cs[x]++;
            cg[y]++;
        }

        for (int i = 0; i < 10; i++)
            cow += min(s[i], g[i]);

        return to_string(bull) + "A" + to_string(cow - bull) + "B";
    }
};