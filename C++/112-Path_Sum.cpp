/*
 112. Path Sum (E)

 Preorder(top-down)
 Preorder the tree, if the path sum isn't fullfill the given sum, move to its 
 child and add its value
 T:O(n)
 S:O(leaf)

 Preorder(top-down) recursion
 If the current node isn't a leaf, deduct sum with the current node value and
 move to its child 
 T:O(n)
 S:O(depth)
 
*/

// Preorder(top-down)
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        // Queue for todo nodes and current sum
        queue<TreeNode*> todo; 
        queue<int> sums;
        todo.push(root);
        sums.push(root->val);

        while (!todo.empty()) { 
            root = todo.front();
            todo.pop();
            int curSum = sums.front();
            sums.pop();
            
            if (!root->left && !root->right && curSum == sum) {
                return true;
            }
            if (root->left) {
                todo.push(root->left);
                sums.push(curSum + root->left->val);
            }
            if (root->right) {
                todo.push(root->right);
                sums.push(curSum + root->right->val);
            }
        }
        return false;
    }
};


// Preorder(top-down) recursion
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        // Use leaf to stop the recursion because we can't know the entry point
        if (!root) return false;
        if (!root->left && !root->right && root->val == sum) { 
            return true;
        }
        return hasPathSum(root->left, sum - root->val) 
            || hasPathSum(root->right, sum - root->val);
    }
};
