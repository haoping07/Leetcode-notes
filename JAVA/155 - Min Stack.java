/*
 155. Min Stack (E)

 Approach 1 : Stack
 Use two stacks, one as the normal stack, one as the min nodes stack
 Time: O(n)
 Space: O(2n)

 Approach 2 : Custom wrap class
 Use a class to wrap the node val and min val
 Time: O(n)
 Space: O(n)

*/

/* Approach 1 */
class MinStack {
    Stack<Integer> stack;
    Stack<Integer> minStack;

    /** initialize your data structure here. */
    public MinStack() {
        stack = new Stack<Integer>();
        minStack = new Stack<Integer>();
    }
    
    public void push(int x) {
        stack.push(x);
        if (minStack.isEmpty()) 
            minStack.push(x);
        else 
            minStack.push(Math.min(x, minStack.peek()));
    }
    
    public void pop() {
        stack.pop();
        minStack.pop();
    }
    
    public int top() {
        return stack.peek();
    }
    
    public int getMin() {
        return minStack.peek();
    }
}


/* Approach 2 */
class MinStack {
    // Custom class
    class Node {
        int val, min;
        public Node(int val, int min) {
            this.val = val;
            this.min = min;
        }
    }
    
    Stack<Node> stack = new Stack<Node>();

    public MinStack() {}

    public void push(int x) {
        if (stack.isEmpty()) 
            stack.push(new Node(x, x));
        else
            stack.push(new Node(x, Math.min(x, stack.peek().min)));
    }
    
    public void pop() {
        stack.pop();
    }
    
    public int top() {
        return stack.peek().val;
    }
    
    public int getMin() {
        return stack.peek().min;
    }
}