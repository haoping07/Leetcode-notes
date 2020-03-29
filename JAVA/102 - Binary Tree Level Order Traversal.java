/*
 102. Binary Tree Level Order Traversal (M)

 Approach 1 : Iteration
 Time: O(n)
 Space: O(n)

 Approach 2 : Recursion
 Time: O(n)
 Space:O(n)

*/

/* Approach 1 */
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {   
        Queue<TreeNode> todo = new LinkedList<>();
        todo.add(root);
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if (root == null) return res;
        while (todo.size() != 0) {
            int size = todo.size();
            List<Integer> sub = new ArrayList<Integer>();
            for (int i = 0; i < size; i++) {
                root = todo.poll();
                sub.add(root.val);
                if (root.left != null) todo.add(root.left);
                if (root.right != null) todo.add(root.right);
            }
            res.add(sub);
        }
        return res;
    }
}


/* Approach 2 */
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        DFS(root, 1, res);
        return res;
    }
    
    public void  DFS(TreeNode root, int depth, List<List<Integer>> res) {
        if (root == null) return;
        if (res.size() < depth) {
            res.add(new ArrayList<Integer>());
            res.get(depth - 1).add(root.val);
        } 
        else res.get(depth - 1).add(root.val);
        DFS(root.left, depth + 1, res);
        DFS(root.right, depth + 1, res);
    }
}