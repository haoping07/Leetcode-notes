/*
 28. Implement strStr() (E)

 Approach 1 : Brute-Force
 Time: O(m * n)
 Space: O(1)

Approach 2 : Brute-Force (slide windows)
 Time: O(m * n)
 Space: O(1)

*/

/* Approach 1 */
class Solution {
    public int strStr(String haystack, String needle) {
        if (needle.length() == 0) return 0;
        int hlen = haystack.length(), nlen = needle.length();
        for (int i = 0; i <= hlen - nlen; i++) {
            int j = 0;
            for (; j < nlen; j++) {
                if (haystack.charAt(i + j) != needle.charAt(j)) break;
            }
            if (j == nlen) return i;
        }
        return -1;
    }
}

/* Approach 2 */
class Solution {
    public int strStr(String haystack, String needle) {
        if (needle.length() == 0) return 0;
        int wleft = 0, wright = needle.length();

        // Sliding window
        for (int i = 0; i <= haystack.length() - needle.length(); i++) {
            if (haystack.substring(wleft, wright).equals(needle)) return i;
            // Move windwos edge
            wleft++;
            wright++;
        }
        return -1;
    }
}