/*
 98. Validate Binary Search Tree
 Medium
*/

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