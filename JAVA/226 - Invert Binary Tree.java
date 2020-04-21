/*
 226. Invert Binary Tree (E)

 Approach 1 : Preorder BFS
 Time: O(n)
 Space: O(n)

 Approach 2 : Recursion DFS
 Time: O(n)
 Space:O(n), n is the depth of the recursion

*/

/* Approach 1 */
class Solution {
    public TreeNode invertTree(TreeNode root) {
        Queue<TreeNode> todo = new LinkedList<TreeNode>();
        todo.add(root);
        while (!todo.isEmpty()) {
            TreeNode entry = todo.poll();
            if (entry != null) {
                todo.add(entry.left);
                todo.add(entry.right);
                
                // Swap the nodes
                TreeNode tmp = entry.left;
                entry.left = entry.right;
                entry.right = tmp;
            }
        }
        return root;
    }
}


/* Approach 2 */
class Solution {
    public TreeNode invertTree(TreeNode root) {
        TreeInvert(root);
        return root;
    }
    
    public void TreeInvert(TreeNode root) {
        if (root != null) {
            TreeNode tmp = root.left;
            root.left = root.right;
            root.right = tmp;
            TreeInvert(root.left);
            TreeInvert(root.right);
        }
    }
}