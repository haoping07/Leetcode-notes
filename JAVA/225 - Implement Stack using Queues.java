/*
 225. Implement Stack using Queues (E)

 
 Approach 1 : one queue
 Time: O(n)
 Space: O(n)

 Approach 2 : two queues
 Two queues A & B, A as stack style queue, B as the helper to make A stack style.
 Time: O(2n)
 Space: O(2n)

*/

/* Approach 1 */
class MyStack {
    Queue<Integer> q;

    /** Initialize your data structure here. */
    public MyStack() {
        q = new LinkedList<Integer>();
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        int n = q.size();
        q.add(x);
        for (int i = 0; i < n; i++) q.add(q.poll());
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        return q.poll();
    }
    
    /** Get the top element. */
    public int top() {
        return q.peek();
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return q.isEmpty();
    }
}


/* Approach 2 */
class MyStack {
    Queue<Integer> q;
    Queue<Integer> helper;

    /** Initialize your data structure here. */
    public MyStack() {
        q = new LinkedList<Integer>();
        helper = new LinkedList<Integer>();
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        helper.add(x);
        while (!q.isEmpty()) helper.add(q.poll());
        while (!helper.isEmpty()) q.add(helper.poll());
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        return q.poll();
    }
    
    /** Get the top element. */
    public int top() {
        return q.peek();
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return q.isEmpty();
    }
}