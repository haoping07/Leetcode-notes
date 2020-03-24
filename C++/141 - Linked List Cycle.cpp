/*
 141. Linked List Cycle (E)

 Approach 1 : Fast-Slow Pointer
 1. Make slow pointer points to node, fast pointer points to node->next
 2. If slow == fast: cycle exist
    else: Move slow pointer 1 step foward, fast pointer 2 step foward
 Time: O(n)
 Space: O(1)

*/

/* Approach 1 : Fast-Slow Pointer */
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head) return false;
        ListNode* slow = head, * fast = head->next;
        while (fast && fast->next)
        {
            if (slow == fast) return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};