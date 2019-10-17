/*
 2. Add Two Numbers (Medium)

 Notes:
     - O(n)
    Do the addition process one by one and save the result to variable 'carry' in each addition. carry % 10 is the value of
    new node, carry / 10 is the new carry that will be added to the next digit
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* ptr = head;
        int carry = 0;

        while (1)
        {
            if (l1)
            {
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                carry += l2->val;
                l2 = l2->next;
            }

            ptr->val = carry % 10;
            carry /= 10;

            if (l1 || l2 || carry)
            {
                ptr->next = new ListNode(0);
                ptr = ptr->next;
            }
            else
                break;
        }
        return head;
    }
};