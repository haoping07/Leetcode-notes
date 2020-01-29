/*
 232. Implement Queue using Stacks (E)
 
 Notes:
    Store values "upside down" in stack to simulate the queue.
    Use two stacks, "q" and "helper", when user call the Push function, push & pop all elements in "q" stack
    to "helper" stack. After push the new value to "q" stack, take back all elements in "helper" stack. 
*/

class MyQueue {
private:
    stack<int> q, helper;
    
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while (!q.empty())
        {
            helper.push(q.top());
            q.pop();
        }
        q.push(x);
        while (!helper.empty())
        {
            q.push(helper.top());
            helper.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int val = peek();
        q.pop();
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        return q.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return q.empty();
    }
};
