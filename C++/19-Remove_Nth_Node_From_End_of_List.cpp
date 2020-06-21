/*
 19. Remove Nth Node From End of List (Medium)

 Notes:
    fast-slow pointer - O(n)
    Use two pointers to scan the list, when the first pointer points to the Nth node, the second pointer move
    backward from the head and follow the first pointer in the following iteration. When the first pointer
    points to the nullptr, the second pointer is pointing to the n + 1 to last node
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        for (int i = 0; i < n; i++)
            head = head->next;

        ListNode* nth_prev = dummy;
        while (head)
        {
            nth_prev = nth_prev->next;
            head = head->next;
        }

        ListNode* temp = nth_prev->next;
        nth_prev->next = temp->next;
        delete temp;

        return dummy->next;
    }
};
