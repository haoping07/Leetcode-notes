/*
 92 - Reverse Linked List II (M)

 Approach 1 : 
 Record the (m - 1)th node that will be used to concatenate back reverse list,
 reverse the range and concatenate back.
 Time: O(n)
 Space: O(1)

*/

/* Approach 1 */
class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode prev = dummy;
        ListNode cur = head;
        ListNode revPre = null;
        ListNode revCur = null;
        for (int i = 1; i <= n; i++) {
            if (i < m) {
                prev = cur;
                cur = cur.next;
            }
            else {
                if (i == m) {
                    revPrev = prev;
                    revCur = cur;
                }
                ListNode next = revCur.next;
                revCur.next = revPrev;
                revPrev = revCur;
                revCur = next;
            }
        }
        pre.next = revPrev;
        cur.next = revCur;
        return dummy.next;
    }
}