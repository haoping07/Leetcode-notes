/*
 24. Swap Nodes in Pairs (Medium)

 Notes:
    Prenode method - O(n)
    Make a dummy pointer points to head, while head->next and head->next->next not nullptr, do:
    1. Make a backup pointer points to head->next->next
    2. Do swap process
    3. Move head pointer to backup pointer
 */

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (head && head->next)
        {
            ListNode* tmp = head->next->next;
            cur->next = head->next;
            cur = cur->next;
            cur->next = head;
            cur = cur->next;
            cur->next = nullptr;
            head = tmp;
        }
        // Link remaining node, if any
        if (head)
            cur->next = head;
        return dummy->next;
    }
};