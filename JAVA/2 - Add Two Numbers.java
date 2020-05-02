/*
 2. Add Two Numbers (M)

 Approach 1 :
 Scan two lists nodes ony by one, the carry is the sum of the two nodes.
 Use this carry to build the sum list.
 Time: O(max(l1, l2))
 Space: O(max(l1, l2))

*/

/* Approach 1 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(0);
        ListNode ptr = head;
        int carry = 0;
        while (true) {
            if (l1 != null) {
                carry += l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                carry += l2.val;
                l2 = l2.next;
            }
            
            ptr.val = carry % 10;
            carry /= 10;
            
            if (l1 != null || l2 != null || carry != 0) {
                ptr.next = new ListNode(0);
                ptr = ptr.next;
            }
            else break;
        }
        return head;
    }
}


