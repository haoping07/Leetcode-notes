/*
 100. Same Tree (E)

 Approach 1 : Preorder BFS
 Time: O(n)
 Space: O(p + q)

 Approach 2 : Recursion DFS
 Time: O(n)
 Space:O(n), n is the depth of the recursion

*/

/* Approach 1 */
class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        Queue<TreeNode> todo = new LinkedList<TreeNode>();
        todo.add(p);
        todo.add(q);
        while (!todo.isEmpty()) {
            p = todo.poll();
            q = todo.poll();
            
            if (p == null && q == null) continue;
            if (p == null || q == null) return false;
            if (p.val != q.val) return false;
            
            todo.add(p.left);
            todo.add(q.left);
            todo.add(p.right);
            todo.add(q.right);
        }
        return true;
    }
}

/* Approach 2 */
class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null) return true;
        if (p == null || q == null) return false;
        if (p.val != q.val) return false;
        return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }
}