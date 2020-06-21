/*
 299. Bulls and Cows (E)

 Approach 1:
 Use array and two For-loop.
 1. Iterates secret and guess at the same time. If two letter are the same, bull++.
    Counts the appear of letter and stores to the array by its ASCII as key. 
 2. Iterates two arrays at the same time, take the minumum in each and adds to the cow;
 Time: O(secret length + 10)
 Space: O(secret length + guess length)

 Approach 2:
 Optimize Approach 1 to one array and one pass.
 Time: O(secret length)
 Space: O(count length)

*/

// Approach 1
class Solution {
public:
    string getHint(string secret, string guess) {
        int s[10] = { 0 }, g[10] = { 0 };
        int bull = 0, cow = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bull++;
            }
            else {
                s[secret[i] - '0']++;
                g[guess[i] - '0']++;
            }
        }

        for (int i = 0; i < 10; i++) {
            cow += min(s[i], g[i]);
        }

        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};


// Approach 2
class Solution {
public:
    string getHint(string secret, string guess) {
        int freq[10] = { 0 };
        int bull = 0, cow = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bull++;
            }
            else {
                // If the char showed before in guess, increment the cow. Give
                // back the freq.
                int s = secret[i] - '0';
                if (freq[s] < 0) cow++;
                freq[s]++;

                // If the char showed before in secret, increment the cow. Minus
                // the freq.
                int g = guess[i] - '0';
                if (freq[g] > 0) cow++;
                freq[g]--;
            }
        }
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};