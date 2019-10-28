/*
 150. Evaluate Reverse Polish Notation (Medium)

 Notes:
    Stack
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        for (string t : tokens)
        {
            if (t != "+" && t != "-" && t != "*" && t != "/")
                stack.push(stoi(t)); 
            else
            {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                
                if (t == "+")  b += a;
                else if (t == "-") b -= a;
                else if (t == "*") b *= a;
                else b /= a;
                
                stack.push(b);
            }
        }
        return stack.top();
    }
};