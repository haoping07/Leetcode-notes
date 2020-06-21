/*
 394. Decode String (Medium)
 
 Notes:
     Use stack. Transverse the string by s[i]: 
     If s[i] == number:  Convert to string and record;
     If s[i] == '[':     Push number and "[" to stack, let number = 0;
     If s[i] == ']':     Get the string after previous '[', reapeat number times, then push back
                         to stack;
     else:               Convert to string and push to stack;

     Pop all string in stack, reverse them, then return;
*/

class Solution {
public:
    string GetString(stack<string>& s)
    {
        string res = "";
        while (!s.empty())
        {
            res += s.top();
            s.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }

    string decodeString(string s) {
        stack<string> stack;
        int number = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (isdigit(s[i]))
                number = number * 10 + (s[i] - '0');
            else if (s[i] == '[')
            {
                stack.push(to_string(number));
                stack.push("[");
                number = 0;
            }
            else if (s[i] == ']')
            {
                string tmp = "";
                while (stack.top() != "[")
                {
                    tmp += stack.top();
                    stack.pop();
                }
                stack.pop();
                int repeat = stoi(stack.top());
                stack.pop();
                for (int j = 0; j < repeat; j++)
                    stack.push(tmp);
            }
            else
            {
                string str(1, s[i]);
                stack.push(str);
            }
        }
        return GetString(stack);
    }
};
