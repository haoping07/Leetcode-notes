/*
 257. Binary Tree Paths (E)

 Approach 1 : Divide-and-conquer
 Time: O(n)
 Space: O(n)

 Approach 2 : BFS iteration
 Time: O(n)
 Space: O(n)

 Approach 3 : BFS recursion
 Time: O(n)
 Space: O(n)

*/

/* Approach 1 */
class Solution {
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> paths = new ArrayList<String>();
        if (root == null) return paths;
        
        List<String> left = binaryTreePaths(root.left);
        List<String> right = binaryTreePaths(root.right);
        
        for (String l : left) paths.add(root.val + "->" + l);
        for (String r : right) paths.add(root.val + "->" + r);
        
        if (paths.size() == 0) paths.add("" + root.val);
        return paths;
    }
}

/* Approach 2 */
class Solution {
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> res = new ArrayList<String>();
        if (root == null) return res;
        Queue<TreeNode> todo = new LinkedList<TreeNode>();
        Queue<String> path = new LinkedList<String>();
        todo.add(root);
        path.add(root.val + "");
        while (!todo.isEmpty()) {
            root = todo.poll();
            String str = path.poll();
            if (root.left != null) {
                todo.add(root.left);
                path.add(str + "->" + root.left.val);
            }
            if (root.right != null) {
                todo.add(root.right);
                path.add(str + "->" + root.right.val);
            }
            if (root.left == null && root.right == null) {
                res.add(str);
            }
        }
        return res;
    }
}

/* Approach 3 */
class Solution {
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> res = new ArrayList<String>();
        if (root == null) return res;
        helper(root, String.valueOf(root.val), res);
        return res;
    }
    
    public void helper(TreeNode root, String path, List<String> res) {
        if (root.left == null && root.right == null) {
            res.add(path);
            return;
        }
        if (root.left != null) {
            helper(root.left, String.valueOf(path + "->" + root.left.val), res);
        }
        if (root.right != null) {
            helper(root.right, String.valueOf(path + "->" + root.right.val), res);
        }
    }
}