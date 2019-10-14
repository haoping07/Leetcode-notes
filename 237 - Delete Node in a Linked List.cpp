/*
 237. Delete Node in a Linked List (Easy)

 How:
    Brute force - O(n)
    Only the node that needs to be deleted is given, we replace this node by its next node connect to its next next node.
    Pay attention to the corner cases: 1. Node doesn't exist 2. Node is the last node
*/

class Solution {
public:
    void deleteNode(ListNode* node) {
        if (!node)
            return;
        if (!node->next)
        {
            node = nullptr;
            return;
        }
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
