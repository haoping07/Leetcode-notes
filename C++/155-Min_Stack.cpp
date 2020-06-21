/*
 155. Min Stack (E)

 Notes:
    Use two vector/Stack to address elements and minimum element
    T: O(n)
    S: O(n)
*/

// Vector Approach
class MinStack {
private:
    vector<int> stk;
    vector<int> minStk;
    
public:
    void push(int x) {
        stk.push_back(x);
        if (minStk.size())
            minStk.push_back(min(x, minStk.back()));
        else
            minStk.push_back(x);
    }
    
    void pop() {
        stk.pop_back();
        minStk.pop_back();
    }
    
    int top() {
        return stk.back();
    }
    
    int getMin() {
        return minStk.back();
    }
};

// Stack STL Approach
class MinStack {
private:
    stack<int> stk, minStk;

public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        stk.push(x);

        if (minStk.empty() || x <= minStk.top())
            minStk.push(x);
    }

    void pop() {
        int top = stk.top();
        stk.pop();

        if (top == minStk.top())
            minStk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minStk.top();
    }
};