/*
 203. Remove Linked List Elements (E)

 Approach 1 : One pointer
 Check if node's next exist, if exist, compare two nodes val and relink. 
 Time: O(n)
 Space: O(1)

*/

/* Approach 1 */
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode node = dummy;
        while (node.next != null) {
            if (node.next.val == val)
                node.next = node.next.next;
            else node = node.next;
        }
        return dummy.next;
    }
}