/*
 141. Linked List Cycle (Easy)

 Notes:
    fast-slow pointer
    1. Make slow pointer points to node
    2. Make fast pointer points to node->next
    When inside the cycle, because fast pointer walks two node at each iterate, it approaches slow pointer step by step.
    If fast pointer catches up slow pointer, it means this linked list have cycle.
*/

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head)
            return false;
        ListNode* slow = head, * fast = head->next;
        while (fast != nullptr && fast->next != nullptr)
        {
            if (slow == fast)
                return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};