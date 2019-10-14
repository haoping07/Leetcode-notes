/*
 92. Reverse Linked List II (Medium)

 How:
    Two pointers & Prenode - O(?)
    Record (m - 1)th and (n + 1)th nodes, reverse the nodes in the range and then connect them back.
*/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || !head->next)
            return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* mth_prev = FindPrev(dummy, m - 1);
        ListNode* mth = mth_prev->next;
        ListNode* nth = FindPrev(dummy, n);
        ListNode* nth_next = nth->next;
        nth->next = nullptr;

        ReverseNode(mth);
        mth_prev->next = nth;
        mth->next = nth_next;

        return dummy->next;
    }

    ListNode* FindPrev(ListNode* head, int k)
    {
        ListNode* prev = nullptr;
        for (int i = 0; i < k; i++)
            head = head->next;
        return head;
    }

    void ReverseNode(ListNode* head)
    {
        ListNode* prev = nullptr;
        while (head)
        {
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
    }
};

