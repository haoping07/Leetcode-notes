/*
 225. Implement Stack using Queues (Easy)

 Notes:
     Store values "upside down" in queue to simulate the stack.
     Similar to Lc.232 Implement Queue using Stacks
*/

class MyStack {
private:
    queue<int> q, helper;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        while (!q.empty())
        {
            helper.push(q.front());
            q.pop();
        }
        q.push(x);
        while (!helper.empty())
        {
            q.push(helper.front());
            helper.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int val = top();
        q.pop();
        return val;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};