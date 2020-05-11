/*
 150. Evaluate Reverse Polish Notation (M)

 Approach 1 : indexOf for operators traversal
 Time: O(n)
 Space: O(n)

 Approach 2 : two stacks
 Time: O(n)
 Space: O(n)

 ** Why using indexOf is faster than switch ?
 hmm.. maybe the number of integer is larger than the number of operators??

*/

/* Approach 1 */
class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<Integer>();
        String ops = "+-*/";
        for (String s : tokens) {
            if (ops.indexOf(s) >= 0) {
                int b = stack.pop(), a = stack.pop();
                if (s.equals("+")) a += b;
                else if (s.equals("-")) a -= b;
                else if (s.equals("*")) a *= b;
                else a /= b;
                stack.push(a);
            }
            else stack.push(Integer.parseInt(s));
        }
        return stack.pop();
    }
}


/* Approach 2 */
class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < tokens.length; i++) {
            if (!tokens[i].equals("+") && !tokens[i].equals("-") && !tokens[i].equals("*") && !tokens[i].equals("/")) {
                stack.push(Integer.parseInt(tokens[i]));
            }
            else {
                int b = stack.pop();
                int a = stack.pop();
                switch (tokens[i]) {
                    case "+":
                        a += b;
                        break;
                    case "-":
                        a -= b;
                        break;
                    case "*":
                        a *= b;
                        break;
                    case "/":
                        a /= b;
                        break;
                }
                stack.push(a);
            }
        }
        return stack.pop();
    }
}

