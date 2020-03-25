/*
 237. Delete Node in a Linked List (E)

 Approach 1 : 
 Time: O(1)
 Space: O(1)

*/

/* Approach 1 */
class Solution {
    public void deleteNode(ListNode node) {
        node.val = node.next.val;
        node.next = node.next.next;
    }
}