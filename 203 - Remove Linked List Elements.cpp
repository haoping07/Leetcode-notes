/*
 203. Remove Linked List Elements (Easy)

 Notes:
    One pointers & Prenode - O(n)
    Use a pointer to scan the list. If the node is duplicate, delete it and connect its previous node to the next one. 
*/

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;
        while (head->next)
        {
            if (head->next->val == val)
            {
                ListNode* del = head->next;
                head->next = del->next;
                delete del;
            }
            else
                head = head->next;
        }
        return dummy->next;
    }
};
