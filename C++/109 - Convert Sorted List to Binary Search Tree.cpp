/*
 109. Convert Sorted List to Binary Search Tree (M)

 Notes:
 Approach 1 : Recursion + BFS
 Build the vector from linklist. Use the middle element in vector as root in each
 round to build the tree
 Time: O(n)
 Space: O(n)
 
 Approach 2 : Linklist traversal + BFS
 Traverse the linklist, cut in the half and BFS each partition
 Time: O(n)
 Space: O(n)

*/

// Approach 1 :
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<TreeNode*> nodes;
        while (head != nullptr)
        {
            nodes.push_back(new TreeNode(head->val));
            head = head->next;
        }
        return BuildTree(nodes, 0, nodes.size() - 1);
    }

    TreeNode* BuildTree(vector<TreeNode*>& nodes, int low, int high)
    {
        if (low > high) return nullptr;
        int mid = low + (high - low) / 2;
        nodes[mid]->left = BuildTree(nodes, low, mid - 1);
        nodes[mid]->right = BuildTree(nodes, mid + 1, high);
        return nodes[mid];
    }
};


// Approach 2 :
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        // Get the middle element in linklist
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode* newNode = new TreeNode(slow->val);

        if (slow != head)
        {
            newNode->right = sortedListToBST(slow->next);

            // Scan from head to middle
            fast = head;
            while (fast->next != slow)
                fast = fast->next;

            // Cut the linklist
            fast->next = nullptr;

            newNode->left = sortedListToBST(head);
        }
        return newNode;
    }
};