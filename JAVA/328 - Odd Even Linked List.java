/*
 328. Odd Even Linked List (M)

 Approach 1 : 
 Address odd and even node individually, then concatenate together. 
 Time: O(n)
 Space: O(1)

*/

/* Approach 1 */
class Solution {
    public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode odd = head;
        ListNode even = head.next;
        ListNode bk = even;
        while (even != null && even.next != null) {
            odd.next = even.next;
            odd = odd.next;
            even.next = odd.next;
            even = even.next;
        }
        odd.next = bk;
        return head;
    }
}