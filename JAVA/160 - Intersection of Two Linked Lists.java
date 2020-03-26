/*
 160. Intersection of Two Linked Lists (E)

 Approach 1 :
 1. Find the length of the two linklist
 2. Iterate the long one from the head to the size of short one
 3. Iterate two linklists, they same node they point to is the intersection  
 Time: O(len(headA) + len(headB))
 Space: O(1)

*/

/* Approach 1 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) return null;
        ListNode curA = headA;
        ListNode curB = headB;
        int lenA = 0;
        int lenB = 0;
        while (curA != null) {
            lenA++;
            curA = curA.next;
        }
        while (curB != null) {
            lenB++;
            curB = curB.next;
        }
        
        curA = headA;
        curB = headB;
        
        while (lenA > lenB) {
            curA = curA.next;
            lenA--;
        }
        while (lenA < lenB) {
            curB = curB.next;
            lenB--;
        }
        while (curA != curB) {
            curA = curA.next;
            curB = curB.next;
        }
        
        return curA;
    }
}
