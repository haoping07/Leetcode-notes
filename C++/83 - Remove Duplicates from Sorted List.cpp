/*
 83. Remove Duplicates from Sorted List (Easy)

 Notes:
    1. fast-slow pointer - O(n)
    Use Two pointers to scan the list, if the two pointers' value are the same, move fast pointer backward, else, slow
    pointer's next points to fast pointer node, slow pointer points to fast pointer's node.

    2. One poiner - O(n)
    In the previous method, we skip the duplicate nodes, this causes memory leak.
    The better solution should be using a pointer to scan the list, if the next node value is same as the current one,
    delete the duplicate and point the current one's next to the next next one.
*/

// One pointer
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* node = head;
        while (node && node->next)
        {
            if (node->val == node->next->val)
            {
                ListNode* temp = node->next;
                node->next = node->next->next;
                delete temp;
            }
            else
                node = node->next;
        }
        return head;
    }
};


/*
// Fast-slow pointer (Not recommended)

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return head;
        ListNode* slow = head, * fast = head;
        while (fast)
        {
            if (slow->val != fast->val)
            {
                slow->next = fast;
                slow = fast;
                fast = fast->next;
            }
            else
                fast = fast->next;
        }
        slow->next = fast;
        return head;
    }
};

*/