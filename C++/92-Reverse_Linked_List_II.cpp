/*
 92. Reverse Linked List II (Medium)

 Notes:
    Two pointers & Prenode
    Record (m - 1)th and (n + 1)th nodes, reverse the nodes in the range and then connect them back.
*/

// Approach 1 - O(n)
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = head;
        ListNode* reversePre = nullptr;
        ListNode* reverseCur = nullptr;
        for (int i = 1; i <= n; i++)
        {
            if (i < m)
            {
                pre = cur;
                cur = cur->next;
            }
            else
            {
                if (i == m)
                {
                    reversePre = pre;
                    reverseCur = cur;
                }
                ListNode* next = reverseCur->next;
                reverseCur->next = reversePre;
                reversePre = reverseCur;
                reverseCur = next;
            }
        }
        pre->next = reversePre;
        cur->next = reverseCur;
        return dummy->next;
    }
};

// Approach 2
/*
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
*/