/*
 66. Plus One (E)

 Notes:
 Approach 1 :
 Time: O(d), d is the number of digit
 Space: O(1)

*/

// Approach 1 :
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        add(digits, 1);
        return digits;
    }

private:
    void add(vector<int>& digits, int carry)
    {
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }
        if (carry)
            digits.insert(digits.begin(), carry);
    }
};