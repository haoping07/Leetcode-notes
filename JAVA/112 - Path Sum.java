/*
 112. Path Sum (E)

 Approach 1 : 
 Time: O(n)
 Space: O(1)

 Approach 2 : DFS 
 Time: O(n)
 Space: O(2n)

*/

/* Approach 1 */
class Solution {
    public boolean hasPathSum(TreeNode root, int sum) {
        if (root == null) return false;
        else if (root.val == sum && root.left == null && root.right ==null)
            return true;
        else 
            return hasPathSum(root.left, sum - root.val) || hasPathSum(root.right, sum - root.val);
    }
}

/* Approach 2 */
class Solution {
    public boolean hasPathSum(TreeNode root, int sum) {
        if (root == null) return false;
        Stack<TreeNode> todo = new Stack<TreeNode>();
        Stack<Integer> sumStack = new Stack<Integer>();
        todo.push(root);
        sumStack.push(root.val);
        while (!todo.empty()) {
            root = todo.pop();
            int sumTmp = sumStack.pop();
            
            if (root.left == null && root.right == null && sumTmp == sum)
                return true;
            
            if (root.right != null) {
                todo.push(root.right);
                sumStack.push(sumTmp + root.right.val);
            }
            if (root.left != null) {
                todo.push(root.left);
                sumStack.push(sumTmp + root.left.val);
            }
        }
        return false;
    }
}