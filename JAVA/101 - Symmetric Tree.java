/*
 101. Symmetric Tree (E)

 Approach 1 : Preorder BFS
 Time: O(n)
 Space: O(n)

 Approach 2 : Recursion DFS
 Time: O(n)
 Space:O(n), n is the depth of the recursion

*/

/* Approach 1 */
class Solution {
    public boolean isSymmetric(TreeNode root) {
        if (root == null) return true;
        Queue<TreeNode> todo = new LinkedList<TreeNode>();
        todo.add(root.left);
        todo.add(root.right);
        while (!todo.isEmpty()) {
            TreeNode p = todo.poll();
            TreeNode q = todo.poll();
            
            if (p == null && q == null) continue;
            if (p == null || q == null) return false;
            if (p.val != q.val) return false;
            
            todo.add(p.left);
            todo.add(q.right);
            todo.add(p.right);
            todo.add(q.left);
        }
        return true;
    }
}


/* Approach 2 */
class Solution {
    public boolean isSymmetric(TreeNode root) {
        if (root == null) return true;
        return isSymmetric(root.left, root.right);
    }
    
    public boolean isSymmetric(TreeNode p, TreeNode q) {
        if (p == null && q == null) return true;
        if (p == null || q == null) return false;
        if (p.val != q.val) return false;
        return isSymmetric(p.left, q.right) && isSymmetric(p.right, q.left);
    }
}

