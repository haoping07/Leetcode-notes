/*
 87. Scramble String (H)

 Approach 1 : Brute force
 Solution ref. (https://youtu.be/sETxfdHwxc0)
 Try all possible paritions
 Time: O(n^5)?
 Space: O(n^4)?

*/

/* Approach 1 */
class Solution {
    public boolean isScramble(String s1, String s2) {
        if (s1.length() != s2.length()) return false;
        if (s1.equals(s2)) return true;
        
        // Check if partition not character equal
        // If not doing this, Time Limit Exceeded will occur	
        int[] count = new int[26];
        for (int i = 0; i < s1.length(); i++) {
            count[s1.charAt(i) - 'a']++;
            count[s2.charAt(i) - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return false;
        }
        
        // Compare each possible partition
        int size = s1.length();
        for (int i = 1; i < size; i++) {
            if (isScramble(s1.substring(0, i), s2.substring(0, i))
               && isScramble(s1.substring(i, size), s2.substring(i, size))
               || isScramble(s1.substring(0, i), s2.substring(size - i, size))
               && isScramble(s1.substring(i, size), s2.substring(0, size - i))) {
                return true;
            }
        }
        return false;
    }
}