/*
 98. Validate Binary Search Tree (M)
 
 Notes:
    Approach 1 : Inorder characteristic
    Inorder traversal result is sorted.
    Time: O(n + n), n is node number
    S: O(n), n is node number
    
    Approach 2 : Divide and Conquer
    Record each node as its child node's Maximum / Minimum edge.
    Use [Node] to record the max / min edge because sometimes the givien node's value
    excceed INT_MAX / INT_MIN
    Time: O(n), n is node number
    Space: O(n), n is node number

*/

// Approach 1 : Inorder characteristic
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        inorder(root);
        int size = listNode.size();
        for (int i = 0; i < size - 1; i++) 
        {
            if (listNode[i] >= listNode[i + 1])
                return false;
        }
        return true;
    }

    void inorder(TreeNode* root)
    {
        if (!root) return;
        inorder(root->left);
        listNode.push_back(root->val);
        inorder(root->right);
    }
private:
    vector<int> listNode;
};

// Approach 2 : Divide and Conquer
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return DAC(root, nullptr, nullptr);
    }

    bool DAC(TreeNode* root, TreeNode* low, TreeNode* high)
    {
        if (!root) return true;
        if (high && root->val >= high->val) return false;
        if (low && root->val <= low->val) return false;
        return DAC(root->left, low, root) && DAC(root->right, root, high);
    }
};