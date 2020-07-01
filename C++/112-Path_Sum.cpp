/*
 112. Path Sum (E)

 A1: Preorder(top-down)
 Preorder the tree, if the path sum isn't fullfill the given sum, move to its 
 child and add its value
 Time: O(n)
 Space: O(leaf)

 A2: Preorder(top-down) recursion
 If the current node isn't a leaf, deduct sum with the current node value and
 move to its child 
 Time: O(n)
 Space: O(depth)
 
*/

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        // Queue for to-do nodes
        queue<TreeNode*> todo; 
        // Queue for the path sums
        queue<int> sums;
        
        // Init the algo
        todo.push(root);
        sums.push(root->val);
        
        while (!todo.empty()) {
            
            // Get the to-do node and its path sum 
            root = todo.front();
            todo.pop();
            int curSum = sums.front();
            sums.pop();
            
            // If the to-do node is a leaf, check if fullfill the given sum
            if (!root->left && !root->right && curSum == sum) {
                return true;
            }
            
            // If the to-do node is not a leaf, update the queue
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


// A2
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
