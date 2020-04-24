/*
 49. Group Anagrams (M)

 Approach 1 : 
 Time: O(strs.length)
 Space: O(strs.length)

*/

/* Approach 1 */
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<String, List<String>>();
        
        for (String str : strs) {
            // Make sub String to char array
            char[] chars = str.toCharArray();      
            
            // Sort the char array and convert back to string
            Arrays.sort(chars);        
            String s = new String(chars);
            
            // Use string as key to store the str
            if (!map.containsKey(s)) {
                map.put(s, new ArrayList<String>());
            }
            map.get(s).add(str);
        }
        
        return new ArrayList<List<String>>(map.values());
    }
}