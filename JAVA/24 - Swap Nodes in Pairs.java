/*
 24. Swap Nodes in Pairs (M)

 Approach 1 : Iteration
 Time: O(n)
 Space: O(1)

 Approach 2 : Recursion
 Time: O(n)
 Space:O(n)

*/

/* Approach 1 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode(0);
        ListNode prev = dummy;
        while (head != null && head.next != null) {
            ListNode tmp = head.next.next;
            prev.next = head.next;
            head.next.next = head;
            head.next = null;
            prev = head;
            head = tmp;
        }
        if (head != null) prev.next = head;
        return dummy.next;
    }
}


/* Approach 2 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode tmp = head.next;
        head.next = swapPairs(head.next.next);
        tmp.next = head;
        return tmp;
    }
}