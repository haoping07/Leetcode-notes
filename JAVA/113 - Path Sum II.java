/*
 113. Path Sum II (M)

 Approach 1 : DFS
 Time: O(n)
 Space: O(n)

*/

/* Approach 1 */
class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        DFS(root, sum, new ArrayList<Integer>(), res);
        return res;
    }
    
    public void DFS(TreeNode root, int sum, List<Integer> cur, List<List<Integer>> res) {
        if (root == null) return;
        
        cur.add(root.val);
        
        if (root.left == null && root.right == null && root.val == sum) {
            res.add(new ArrayList<Integer>(cur));
        }
        
        DFS(root.left, sum - root.val, cur, res);
        DFS(root.right, sum - root.val, cur, res);
        cur.remove(cur.size() - 1);
    }
}