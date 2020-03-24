/*
 369. Plus One Linked List (Medium)

 Notes:
    Two pointers & Prenode - O(2n)
    Use two pointers, slow and fast, to scan the list. Fast pointer first scan the list, if the node's value
    is not 9, move slow pointer to that node. When fast pointer reach the last node, if last node is not 9,
    then val++, else, slow's value++ and set all nodes after slow pointer to 0
*/

class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        while (fast->next)
        {
            fast = fast->next;
            if (fast->val != 9)
                slow = fast;
        }

        if (fast->val != 9)
            fast->val++;
        else
        {
            slow->val++;
            slow = slow->next;
            while (slow)
            {
                slow->val = 0;
                slow = slow->next;
            }
        }

        if (dummy->val == 0)
            return dummy->next;

        return dummy;
    }
};