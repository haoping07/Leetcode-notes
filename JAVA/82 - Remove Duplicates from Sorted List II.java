/*
 82. Remove Duplicates from Sorted List II (M)

 Approach 1 : Slow-Fast pointer
 Use two pointers to scan the list, slow pointers always point to the previous node
 of the first duplicate node, fast pointer iterates through the duplicate node and
 stop at the last duplicate node. If no duplicate node in a iteration, move slow and
 fast pointer backward.
 Time: O(n)
 Space: O(1)

*/

/* Approach 1 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode slow = dummy;
        ListNode fast = head;
        while (fast != null) {
            while (fast.next != null && fast.val == fast.next.val)
                fast = fast.next;
            if (slow.next == fast) {
                slow = fast;
                fast = fast.next;
            }
            else {
                slow.next = fast.next;
                fast = fast.next;
            }
        }
        return dummy.next;
    }
}

