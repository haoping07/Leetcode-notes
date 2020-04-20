/*
 151. Reverse Words in a String (M)

 Approach 1 : Split
 Time: O(s.length() + n), split() is O(s.length())
 Space: O(n), n is the number of splitted string

 Approach 2 : Stack, no split
 Iterate the string, if meet space, push into stack.
 Time: O(s.length() + n), n is the number of sub string
 Space: O(n), stack with n elements

*/

/* Approach 1 */
class Solution {
    public String reverseWords(String s) {
        String[] arr = s.split(" ");
        StringBuilder res = new StringBuilder();
        for (int i = arr.length - 1; i >= 0; i--) {
            if (!arr[i].equals("")) {
                if (res.length() > 0) {
                    res.append(" ");
                }
                res.append(arr[i]);
            }
        }
        return res.toString();
    }
}

/* Approach 2 */
class Solution {
    public String reverseWords(String s) {
        Stack<String> stack = new Stack<String>();
        String str = "";
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != ' ') 
                str += s.charAt(i);
            else if (s.charAt(i) == ' ' && !str.equals("")) {
                stack.push(str);
                str = "";
            }
        }
        if (!str.equals("")) stack.push(str);
        
        StringBuilder res = new StringBuilder();
        while (!stack.empty()) {
            res.append(stack.pop());
            if (stack.size() > 0) res.append(" ");
        }
        return res.toString();
    }
}