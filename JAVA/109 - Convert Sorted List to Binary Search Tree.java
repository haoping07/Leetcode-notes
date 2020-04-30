/*
 109. Convert Sorted List to Binary Search Tree (M)
 
 Approach 1 : partition
 Find the middle element of list using slow/fast pointer.
 Build tree node by middle element, then cut the list, recurse the left and 
 right paritition.
 Time: O(n)
 Space: O(n)

*/

/* Approach 1 */
class Solution {
    public TreeNode sortedListToBST(ListNode head) {
        if (head == null) return null;
        if (head.next == null) return new TreeNode(head.val);
        
        // Find the middle element of the list
        ListNode slow = head;
        ListNode fast = head.next;
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        
        // Build the tree
        ListNode root = slow.next;
        TreeNode rootNode = new TreeNode(root.val);
        rootNode.right = sortedListToBST(root.next);
        slow.next = null;
        rootNode.left = sortedListToBST(head);
        
        return rootNode;
    }
}
