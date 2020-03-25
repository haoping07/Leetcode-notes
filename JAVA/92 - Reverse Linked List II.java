/*
 92 - Reverse Linked List II (M)

 Approach 1 : 
 Reverse the range and concatenate two sides
 Time: O(n)
 Space: O(1)

*/

/* Approach 1 */
class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode pre = dummy;
        ListNode cur = head;
        ListNode reversePre = null;
        ListNode reverseCur = null;
        for (int i = 1; i <= n; i++) {
            if (i < m) {
                pre = cur;
                cur = cur.next;
            }
            else {
                if (i == m) {
                    reversePre = pre;
                    reverseCur = cur;
                }
                ListNode next = reverseCur.next;
                reverseCur.next = reversePre;
                reversePre = reverseCur;
                reverseCur = next;
            }
        }
        pre.next = reversePre;
        cur.next = reverseCur;
        return dummy.next;
    }
}