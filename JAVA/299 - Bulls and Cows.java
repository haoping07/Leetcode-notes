/*
 299. Bulls and Cows (E)

 Approach 1 :
 Use array and two For-loop.
 1. Iterates secret and guess at the same time. If two letter are the same, bull++.
    Counts the appear of letter and stores to the array by its ASCII as key. 
 2. Iterates two arrays at the same time, take the minumum in each and adds to the cow;
 * The amount of cow is all exist numbers (whether the position is wrong) - position is correct (bull)
 Time: O(n)
 Space: O(n)

 Approach 2 :
 Optimize approach 1 to only using one array
 Time: O(n)
 Space: O(n)

*/

/* Approach 1 */
class Solution {
    public String getHint(String secret, String guess) {
        int[] s = new int[10];
        int[] g = new int[10];
        int bull = 0, cow = 0;
        for (int i = 0; i < secret.length(); i++) {
            int x = secret.charAt(i) - '0';
            int y = guess.charAt(i) - '0';
            if (x == y) bull++;
            s[x]++;
            g[y]++;
        }
        
        for (int i = 0; i < 10; i++) {
            cow += Math.min(s[i], g[i]);
        }
        
        StringBuilder str = new StringBuilder();
        return str.append(bull).append("A").append(cow - bull).append("B").toString();
    }
}

/* Approach 2 */
class Solution {
    public String getHint(String secret, String guess) {
        int[] count = new int[10];
        int bull = 0, cow = 0;
        for (int i = 0; i < secret.length(); i++) {
            if (secret.charAt(i) == guess.charAt(i)) {
                bull++;
            }
            else {
                int d1 = secret.charAt(i) - '0';
                if(count[d1] < 0) {
                    cow++;
                }
                count[d1]++;
            
                int d2 = guess.charAt(i) - '0';
                if (count[d2] > 0) {
                    cow++;
                }
                count[d2]--;
            }
        }
        
        StringBuilder str = new StringBuilder();
        return str.append(bull).append("A").append(cow).append("B").toString();
    }
}