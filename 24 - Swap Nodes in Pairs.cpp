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
        
        // Recursion
        if (!head || !head->next) return head;
        ListNode* next = head->next;
        head->next = swapPairs(head->next->next);
        next->next = head;
        return next;
        
        // Iteration
        /*
        if (!head) return nullptr;
        ListNode* dummy = new ListNode(0);
        ListNode* cur = head;
        ListNode* prev = dummy;
        while (cur && cur->next)
        {
            ListNode* next = cur->next->next;
            prev->next = cur->next;
            prev->next->next = cur;
            prev = cur;
            cur->next = nullptr;
            cur = next;
        }
        if (cur) prev->next = cur;
        return dummy->next;
        */
    }
};