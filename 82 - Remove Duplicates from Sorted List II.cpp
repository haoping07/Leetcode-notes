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
        head = dummy;
        ListNode* fast = head->next;
        while (fast)
        {
            while (fast->next && fast->val == fast->next->val)
            {
                ListNode* del = fast;
                fast = fast->next;
                delete del;
            }
            if (head->next != fast)
            {
                head->next = fast->next;
                delete fast;
                fast = head->next;
            }
            else
            {
                head = head->next;
                fast = fast->next;
            }
        }
        return dummy->next;
    }
};