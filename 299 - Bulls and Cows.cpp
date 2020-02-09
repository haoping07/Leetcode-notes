/*
 299. Bulls and Cows (E)

 Notes:
    Use hashmap (array) and two For-loop.
    First loop (Count bull): iterate each letter in string secret and guess. 
    If two letters are same, bull++. Count the appear of letter and store in the hashmap
    Second loop (Count cow): iterate two letter-count array and take the minumum in each. 
    The total amount of the count - bull is cow
    T: O(n)
    S: O(1)

*/

class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0, cow = 0;
        int cs[10] = { 0 }, cg[10] = { 0 };
        for (int i = 0; i < secret.size(); i++)
        {
            int x = secret[i] - '0';
            int y = guess[i] - '0';
            if (x == y) bull++;
            cs[x]++;
            cg[y]++;
        }

        for (int i = 0; i < 10; i++)
            cow += min(cs[i], cg[i]);

        return to_string(bull) + "A" + to_string(cow - bull) + "B";
    }
};