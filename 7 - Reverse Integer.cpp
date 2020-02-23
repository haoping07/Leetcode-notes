/*
 7. Reverse Integer (E)

 Notes:
 Approach 1 : 
 Time: O(d), d is the number of digit
 Space: O(d)

*/

// Approach 1 :
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0)
        {
            if (rev > INT_MAX / 10)
                return 0;
            if (rev < INT_MIN / 10)
                return 0;
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev;
    }
};


// Approach 1 : 
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0)
        {
            int mod = x % 10;
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && mod > INT_MAX % 10))
                return 0;
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && mod < INT_MIN % 10))
                return 0;
            res = res * 10 + mod;
            x /= 10;
        }
        return res;
    }
};