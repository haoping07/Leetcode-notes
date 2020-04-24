/*
 290. Word Pattern (E)

 Approach 1 : 
 Time: O(n)
 Space: O(n)

*/

/* Approach 1 */
class Solution {
    public boolean wordPattern(String pattern, String str) {
        Map<Character, String> map = new HashMap<Character, String>();
        String[] strs = str.split(" ");
        if (pattern.length() != strs.length) return false;
        for (int i = 0; i < pattern.length(); i++) {
            char p = pattern.charAt(i);
            if (!map.containsKey(p)) {
                if (map.containsValue(strs[i])) 
                    return false;
                map.put(p, strs[i]);
            }
            else {
                if (!strs[i].equals(map.get(p)))
                    return false;
            }
        }
        return true;
    }
}