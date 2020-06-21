/*
 392. Is Subsequence (E)

 Notes:
 Approach 1 :
 Time: O(len(t))
 Space: O(1)

*/

// Approach 1 :
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for (int j = 0; i < s.size(), j < t.size(); j++)
        {
            if (s[i] == t[j])
                i++;
        }
        return i == s.size();
    }
};