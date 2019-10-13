/*
 206. Reverse Linked List (Easy)
 
 How: 
    Make pointer prev points to nullptr, then:
    1. Backup head->next
    2. head->next points to prev node
    3. Make prev pointer points to head
    4. Make head node points to step 1 backup node
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head != nullptr)
        {
            ListNode* tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        return prev;
    }
};





