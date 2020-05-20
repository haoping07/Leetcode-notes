/*
 299. Bulls and Cows (E)

 Approach 1 : Use two freq array
 Loop secret and guess array at the same time, if element match, increment bull;  
 If not match, increment their frequency to the separate frequency array. Scan 
 two frequency arrays at the same time and sum the minimum frequency of the two. (cow) 
 Time: O(n + 10)
 Space: O(2n)

 Approach 2 : Use one freq array
 Loop secret and guess array at the same time, If element match, increment bull;
 If not match, increment their frequency to AN frequency array and count the cow. 
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
            if (secret.charAt(i) == guess.charAt(i))
                bull++;
            else {
                s[secret.charAt(i) - '0']++;
                g[guess.charAt(i) - '0']++;
            }
        }
        
        for (int i = 0; i < 10; i++) {
            cow += Math.min(s[i], g[i]);
        }
        
        StringBuilder str = new StringBuilder();
        return str.append(bull).append("A").append(cow).append("B").toString();
    }
}

/* Approach 2 */
class Solution {
    public String getHint(String secret, String guess) {
        int[] freq = new int[10];
        int bull = 0, cow = 0;
        for (int i = 0; i < secret.length(); i++) {
            // If the number match, increment the bull
            if (secret.charAt(i) == guess.charAt(i))
                bull++;
            // If not match, count the cow
            else {
                int s = secret.charAt(i) - '0';
                // If the number was showed in guess before and now is in secret,
                // increment the cow.
                if (freq[s] < 0) cow++;
                // and increment its frequency
                freq[s]++;
                
                int g = guess.charAt(i) - '0';
                // If the number was showed in secret before and now is in guess,
                // increment the cow.
                if (freq[g] > 0) cow++;
                // and decrement its frequency
                freq[g]--;
            }
        }
        
        StringBuilder str = new StringBuilder();
        return str.append(bull).append("A").append(cow).append("B").toString();
    }
}