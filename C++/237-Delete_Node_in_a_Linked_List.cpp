/*
 237. Delete Node in a Linked List (E)

 Notes:
    Replace the given node value with the next node value, link its next to next next node.
    Don't forget to delete the node using 'delete'
*/

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* tmp = node->next;
        node->val = node->next->val;
        node->next = node->next->next;        
        delete tmp;
    }
};