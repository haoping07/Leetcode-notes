/*
 111. Minimum Depth of Binary Tree (E)
 
 A1: DFS (Btm-top)
 Iterate to the leaf and return the smaller increment depth one level by level.
 Beware of returning the "0" depth left or right child.
 We don't use top-btm approach here because it will need to init the depth to 
 INIT_MAX first which complicates the problem.
 Time: O(n)
 Space: O(n)

 A2: Preoder (level by level)
 Time: O(n)
 Space: O(n)

*/

// A1
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        
        // Get the left and right child minimum depth
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        
        // If one of it is zero, avoid returning it
        if (left == 0 || right == 0) 
            return left + right + 1;
        
        // Otherwise, return the smaller one
        return min(left, right) + 1;
    }
};


// A2
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int count = 0;
        queue<TreeNode*> todo;
        todo.push(root);

        while (!todo.empty())
        {
            int size = todo.size();
            count++;
            for (int i = 0; i < size; i++)
            {
                root = todo.front();
                todo.pop();
                if (!root->left && !root->right) return count;
                if (root->left) todo.push(root->left);
                if (root->right) todo.push(root->right);
            }
        }
        return -1;
    }
};
