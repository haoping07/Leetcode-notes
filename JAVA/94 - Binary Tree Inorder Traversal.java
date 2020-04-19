/*
 94. Binary Tree Inorder Traversal (M)

 Approach 1 : Iteration
 Time: O(n)
 Space: O(n)

 Approach 2 : Recursion
 Time: O(n)
 Space: O(n)

*/

/* Approach 1 */
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>();
        Stack<TreeNode> todo = new Stack<TreeNode>();
        while (!todo.empty() || root != null) {
            while (root != null) {
                todo.push(root);
                root = root.left;
            }
            root = todo.pop();
            res.add(root.val);
            root = root.right;
        }
        return res;
    }
}


/* Approach 2 */
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>();
        DFS(root, res);
        return res;
    }
    
    public void DFS(TreeNode root, List<Integer> res) {
        if (root == null) return;
        DFS(root.left, res);
        res.add(root.val);
        DFS(root.right, res);
    }
}
