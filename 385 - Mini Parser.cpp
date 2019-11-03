/*
 385. Mini Parser (Medium)

*/

class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s.empty())
            return NestedInteger();
        if (s[0] != '[')
            return NestedInteger(stoi(s));

        stack<NestedInteger> stack;
        int start = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '[')
            {
                stack.push(NestedInteger());
                start = i + 1;
            }
            else if (s[i] == ',' || s[i] == ']')
            {
                if (i > start)
                    stack.top().add(NestedInteger(stoi(s.substr(start, i - start))));
                if (s[i] == ']')
                {
                    if (stack.size() > 1)
                    {
                        NestedInteger t = stack.top();
                        stack.pop();
                        stack.top().add(t);
                    }
                }
                start = i + 1;
            }
        }
        return stack.top();
    }
};
