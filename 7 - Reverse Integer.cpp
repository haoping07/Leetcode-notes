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