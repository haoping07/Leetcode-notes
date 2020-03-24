/*
 206. Reverse Linked List (E)

 Approach 1 : Iteration
 Time: O(n)
 Space: O(1)

 Approach 2 : Recursion
 Time: O(n)
 **Space: O(n) (Can I optimize this to O(1)?)

*/

/* Approach 1 : Iteration */
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


/* Approach 2 : Recursion */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        return Rev(nullptr, head);
    }

    ListNode* Rev(ListNode* prev, ListNode* head)
    {
        ListNode* next = head->next;
        head->next = prev;
        if (!next) return head;
        return Rev(head, next);
    }
};




