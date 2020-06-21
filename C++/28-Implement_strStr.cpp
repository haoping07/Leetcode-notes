/*
 28. Implement strStr() (E)

 Approach 1 : n-gram
 Time: O(h * n), h is haystack.size(), n is needle.size()
 Space: O(1)

*/

/* Approach 1 : n-gram */
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") return 0;
        if (haystack == "") return -1;
        int hSize = haystack.size();
        int nSize = needle.size();
        for (int i = 0; i <= hSize - nSize; i++)
        {
            int j = 0;
            for (; j < nSize; j++)
            {
                if (haystack[i + j] != needle[j])
                    break;
            }
            if (j == nSize) return i;
        }
        return -1;
    }
};

