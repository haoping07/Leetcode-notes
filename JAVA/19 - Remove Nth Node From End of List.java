/*
 19. Remove Nth Node From End of List (M)

 Approach 1 :
 Move ptr1 from head to (n + 1) position, then make ptr2 point to dummy and 
 follow the ptr1, while ptr1 points to null, the ptr2 will point to the previous 
 node of Nthnode from end of list. Remove the node
 Time: O(n)
 Space: O(1)

*/

/* Approach 1 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        
        ListNode dummy = new ListNode(0);
        dummy.next = head;

        for (int i = 0; i < n; i++) 
            head = head.next;        
        
        ListNode prev = dummy;
        
        while (head != null) {
            head = head.next;
            prev = prev.next;
        }
        
        prev.next = prev.next.next;
        return dummy.next; 
    }
}

