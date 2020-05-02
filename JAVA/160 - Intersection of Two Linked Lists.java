/*
 160. Intersection of Two Linked Lists (E)

 Approach 1 :
 Iterate two lists to find each length, then iterate again the list with longer
 length till the remaining number of nodes is same as the length of the shorter list.
 Iterate both iterate ptr till they point to the same node. The node will be the intersect
 node.
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
