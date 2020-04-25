/*
 206. Reverse Linked List (E)

 Approach 1 : Iteration
 Time: O(n)
 Space: O(1)

Approach 2 : Recursion
 Time: O(n)
 Space: O(n)

*/

/* Approach 1 */
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        while (head != null) {
            ListNode next = head.next;
            head.next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
}

/* Approach 2 */
class Solution {
    public ListNode reverseList(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode newHead = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return newHead;
    }
}