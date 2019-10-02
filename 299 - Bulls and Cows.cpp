/*
 299. Bulls and Cows
 Easy
*/

class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0, b = 0;
        int arr1[10] = { 0 }, arr2[10] = { 0 };
        for (int i = 0; i < secret.size(); i++)
        {
            int x = secret[i] - '0';
            int y = guess[i] - '0';
            if (x == y)
                a++;
            arr1[x]++;
            arr2[y]++;
        }

        for (int i = 0; i < 10; i++)
            b += min(arr1[i], arr2[i]);

        return to_string(a) + "A" + to_string(b - a) + "B";
    }
};