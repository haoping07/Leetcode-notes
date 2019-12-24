/*
 82. Remove Duplicates from Sorted List II (Medium)

 Notes: 
    fast-slow pointer - O(n)
    Use two pointers to scan the list, slow pointers always point to the previous node of the first duplicate node,
    fast pointer iterates through the duplicate node and stop at the last duplicate node. If no duplicate node in 
    a iteration, move slow and fast pointer backward.
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = head;
        while (fast)
        {
            while (fast->next && fast->val == fast->next->val)
                fast = fast->next;
            if (slow->next != fast)
            {
                slow->next = fast->next;
                fast = fast->next;
            }
            else
            {
                slow = fast;
                fast = fast->next;
            }
        }
        return dummy->next;
    }
};


// Hard to read
/*
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;
        while (head->next && head->next->next)
        {
            if (head->next->val == head->next->next->val)
            {
                int val = head->next->val;
                while (head->next && head->next->val == val)
                {
                    ListNode* tmp = head->next;
                    head->next = head->next->next;
                    delete tmp;
                }
            }
            else
                head = head->next;
        }
        return dummy->next;
    }
};
*/