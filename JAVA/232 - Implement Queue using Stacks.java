/*
 232. Implement Queue using Stacks (E)

 Approach 1 : two stacks
 Use two stacks A & B, A as queue style stack, B as helper for reverse the A
 stack to make it "queue style".
 Time: push() - O(2n), pop() - O(1), empty() - O(1), peek() - O(1)
 Space: O(2n)

*/

/* Approach 1 */
class MyQueue {
    Stack<Integer> stack;
    Stack<Integer> helper;

    /** Initialize your data structure here. */
    public MyQueue() {
        stack = new Stack<Integer>();
        helper = new Stack<Integer>();
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        // Reverse the stack
        while (!stack.isEmpty()) helper.push(stack.pop());
        helper.push(x);
        while (!helper.isEmpty()) stack.push(helper.pop());
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        return stack.pop();
    }
    
    /** Get the front element. */
    public int peek() {
        return stack.peek();
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        return stack.isEmpty();
    }
}