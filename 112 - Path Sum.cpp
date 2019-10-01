/*
 112. Path Sum
 Easy
*/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root)
            return false;
        stack<TreeNode*> nodeStack;
        stack<int> sumStack;
        nodeStack.push(root);
        sumStack.push(root->val);
        while (!nodeStack.empty())
        {
            root = nodeStack.top();
            nodeStack.pop();
            int sumTemp = sumStack.top();
            sumStack.pop();
 
            if (!root->left && !root->right)
            {
                if (sumTemp == sum)
                    return true;
                continue;
            }
 
            if (root->right)
            {
                nodeStack.push(root->right);
                sumStack.push(sumTemp + root->right->val);
            }
 
            if (root->left)
            {
                nodeStack.push(root->left);
                sumStack.push(sumTemp + root->left->val);
            }
        }
 
        return false;
    }
};
