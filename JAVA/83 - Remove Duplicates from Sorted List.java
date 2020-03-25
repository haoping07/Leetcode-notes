/*
 83. Remove Duplicates from Sorted List (E)

 Approach 1 : One pointer
 Look TWO nodes at once. If two nodes have same value, set first node's next to the next one.
 Else, move first node its next
 Time: O(n)
 Space: O(1)

 Approach 2 : Two pointers
 Time: O(n)
 Space:O(1)

*/

/* Approach 1 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode node = head;
        while (node != null && node.next != null) {
            if (node.val == node.next.val)
                node.next = node.next.next;
            else node = node.next;
        }
        return head;
    }
}

/* Approach 2 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null) return head;
        ListNode slow = head;
        ListNode fast = head.next;
        while (fast != null) {
            if (slow.val != fast.val) {
                slow.next = fast;
                slow = slow.next;
            }
            fast = fast.next;
        }
        slow.next = null;
        return head;
    }
}