/*
 155. Min Stack (Easy)

 Notes:
    Use two vector to address stack and minimum data
*/

class MinStack {
private:
    vector<int> stack;
    vector<int> minArr;
    
public:
    void push(int x) {
        stack.push_back(x);
        if (minArr.size())
            minArr.push_back(min(x, minArr.back()));
        else
            minArr.push_back(x);
    }
    
    void pop() {
        stack.pop_back();
        minArr.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return minArr.back();
    }
};