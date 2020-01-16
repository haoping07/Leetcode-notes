/*
 98. Validate Binary Search Tree (M)
 
 Notes:
    Approach 1 : Inorder characteristic
    Inorder traversal result is sorted.
      T: O(2n)    // n is node number
      S: O(n)    // n is node number
    
    Approach 2 : Divide and Conquer
    Record each node as its child node's Maximum / Minimum edge.
    Use [Node] to record the max / min edge because sometimes the givien node's value
    is excceed INT_MAX / INT_MIN
      T: O(n)    // n is node number
      S: O(n)    // n is node number
*/

// Approach 1: Inorder characteristic
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

// Approach 2: Divide and Conquer
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return VBST(root, nullptr, nullptr);
    }

    bool VBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode)
    {
        if (!root) return true;
        if (minNode != nullptr && root->val <= minNode->val)
            return false;
        if (maxNode != nullptr && root->val >= maxNode->val)
            return false;
        return VBST(root->left, minNode, root) &&
            VBST(root->right, root, maxNode);
    }
};