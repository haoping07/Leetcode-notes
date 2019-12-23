/*
 328. Odd Even Linked List (medium)

 Notes:
    Two pointers - O(n)
    Set two pointers point to the odd and even nodes respectively, after finish linking all odd and 
    even nodes, link the head of the even node to the end of the odd node
*/

// Updated: shorter approach
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* bk = even;
        while (even && even->next)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = bk;
        return head;
    }
};

/*
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* podd = head, * peven = head->next;
        ListNode* cur = peven->next, * hodd = head->next;
        while (cur)
        {
            podd->next = cur;
            podd = cur;
            cur = cur->next;
            if (cur)
            {
                peven->next = cur;
                peven = cur;
                cur = cur->next;
            }
        }
        podd->next = hodd;
        peven->next = nullptr;
        return head;
    }
};
*/