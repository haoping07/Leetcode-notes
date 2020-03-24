/*
 141. Linked List Cycle (E)

 Approach 1 : Two pointers
 Time: O(n)
 Space: O(1)

*/

/* Approach 1 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        if (head == null) return false;
        ListNode slow = head;
        ListNode fast = head.next;
        while (fast != null && fast.next != null) {
            if (slow == fast) return true;
            slow = slow.next;
            fast = fast.next.next;
        }
        return false;
    }
}