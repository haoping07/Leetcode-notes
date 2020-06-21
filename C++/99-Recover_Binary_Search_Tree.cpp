/*
 99. Recover Binary Search Tree (H)

 Approach 1 : inorder
 Use inorder traversal to store each node and its val in node and val vector. 
 Sorts the val vector and assigns val back to tree structure. 
 Time: O(n)
 Space: O(n)

 Approach 2 :
 Use three pointers to indicate the first error node, the second error node, and 
 previous visited node. Swap the value of first and second error node
 Time: O(n)
 Space: O(tree height)

 Follow up:
 How to do it with space O(1)?

*/

// Approach 1 : inorder
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> list;
        vector<int> val;
        inorder(root, list, val);
        sort(val.begin(), val.end());
        for (int i = 0; i < list.size(); i++)
            list[i]->val = val[i];
    }

    void inorder(TreeNode* root, vector<TreeNode*>& list, vector<int>& val)
    {
        if (!root) return;
        inorder(root->left, list, val);
        list.push_back(root);
        val.push_back(root->val);
        inorder(root->right, list, val);
    }
};

// Approach 2 : 
class Solution {
public:
    void recoverTree(TreeNode* root) {
        traverse(root);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }

    void traverse(TreeNode* root)
    {
        if (!root) return;
        traverse(root->left);
        if (first == nullptr && prev != nullptr && root->val <= prev->val)
            first = prev;
        if (first != nullptr && root->val <= prev->val)
            second = root;
        prev = root;
        traverse(root->right);
    }

private:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;
};