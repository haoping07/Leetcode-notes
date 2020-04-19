/*
 58. Length of Last Word (E)

 Approach 1 :
 Split the string to array and return the length of the last element
 Time: O(n), for split()
 Space: O(m), number of sub string 

*/

/* Approach 1 */
class Solution {
    public int lengthOfLastWord(String s) {
        s = s.trim();
        if (s.length() == 0) return 0;
        String[] str = s.split(" ");
        return str[str.length - 1].length();
    }
}