/*
 19. Remove Nth Node From End of List (M)

 Approach 1 :
 1. Make dummy node
 2. Move head to n + 1 position from start
 3. Make a newPtr point to dummy
 4. Move head & newPtr foward till the head is null, the newPtr will point to
    the n + 1 node from end
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
        
        ListNode newPtr = dummy;
        
        while (head != null) {
            head = head.next;
            newPtr = newPtr.next;
        }
        
        newPtr.next = newPtr.next.next;
        return dummy.next; 
    }
}

