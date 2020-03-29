/*
 145. Binary Tree Postorder Traversal (H)

 Approach 1 : Iteration
 Time: O(n)
 Space: O(n)

 Approach 2 : Recursion
 Time: O(n)
 Space: O(n) 

*/

/* Approach 1 */
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>();
        Stack<TreeNode> todo = new Stack<TreeNode>();
        TreeNode visited = null;
        while (!todo.empty() || root != null) {
            while (root != null) {
                todo.push(root);
                root = root.left;
            }
            TreeNode peekNode = todo.peek();
            if (peekNode.right != null && peekNode.right != visited)
                root = peekNode.right;
            else {
                todo.pop();
                res.add(peekNode.val);
                visited = peekNode;
            }
        }
        return res;
    }
}


/* Approach 2 */
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>();
        DFS(root, res);
        return res;
    }
    
    public void DFS(TreeNode root, List<Integer> res) {
        if (root == null) return;
        DFS(root.left, res);
        DFS(root.right, res);
        res.add(root.val);
    }
}


