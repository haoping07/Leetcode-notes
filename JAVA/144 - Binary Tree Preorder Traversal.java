/*
 144. Binary Tree Preorder Traversal (M)

 Approach 1 : Iteration
 Time: O(n)
 Space: O(n)

 Approach 2 : Recursion
 Time: O(n)
 Space(n)

*/

/* Approach 1 */
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>();
        Stack<TreeNode> todo = new Stack<TreeNode>();
        while (!todo.empty() || root != null) {
            while (root != null) {
                res.add(root.val);
                todo.push(root);
                root = root.left;
            }
            root = todo.pop();
            root = root.right;
        }
        return res;
    }
}

/* Approach 2 */
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>();
        DFS(root, res);
        return res;
    }
    
    public void DFS(TreeNode root, List<Integer> res) {
        if (root == null) return;
        res.add(root.val);
        DFS(root.left, res);
        DFS(root.right, res);
    }
}
