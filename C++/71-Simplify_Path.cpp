/*
 71. Simplify Path (Medium)

    Notes:
        Consider it as a stack:
            if meet "..",           pop the top
            else if "./" or "/"     do nothing
            else                    push to stack
            
        At the end, don't forget to concatenate the string
*/

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        int start = 0, end = 1, n = path.size();
        while (end < n)
        {
            while (end < n && path[end] != '/')
                end++;
            string str = path.substr(start, end - start);
            if (str == "/" || str == "/.") ;
            else if (str == "/..")
            {
                if (!stack.empty())
                    stack.pop_back();
            }
            else
                stack.push_back(str);
            
            start = end;
            end++;
        }
        
        if (stack.empty())
            return "/";
        
        string joined;
        for (string tmp : stack)
            joined += tmp;
        return joined;
    }
};