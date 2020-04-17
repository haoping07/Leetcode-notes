/*
 299. Bulls and Cows (E)

 Approach 1 :
 Use array and two For-loop.
 1. Iterates secret and guess at the same time. If two letter are the same, bull++.
    Counts the appear of letter and stores to the array by its ASCII as key. 
 2. Iterates two arrays at the same time, take the minumum in each and adds to the cow;
 Time: O(secret length + 10)
 Space: O(secret length + guess length)

 Approach 2 :
 Optimize Approach 1 to one array and one pass.
 Time: O(secret length)
 Space: O(count length)

*/

/* Approach 1 : */
class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0, cow = 0;
        int s[10] = { 0 }, g[10] = { 0 };
        for (int i = 0; i < secret.size(); i++) {
            int x = secret[i] - '0';
            int y = guess[i] - '0';
            if (x == y) bull++;
            else {
                s[x]++;
                g[y]++;
            }
        }

        for (int i = 0; i < 10; i++)
            cow += min(s[i], g[i]);

        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};


/* Approach 2 : */
class Solution {
public:
    string getHint(string secret, string guess) {
        int c[10] = { 0 };
        int bull = 0, cow = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) bull++;
            else {
                int d1 = secret[i] - '0';
                if (c[d1] < 0) cow++;
                c[d1]++;

                int d2 = guess[i] - '0';
                if (c[d2] > 0) cow++;
                c[d2]--;
            }
        }
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};