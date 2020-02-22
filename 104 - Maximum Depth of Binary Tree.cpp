/*
 104. Maximum Depth of Binary Tree (E)
 
 Notes:
 Approach 1 : BFS
 Time: O(n)
 Space: O(n)

 Approach 2 : DFS
 Time: O(n)
 Space: O(n)

*/

// Approahc 1 : BFS
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;

        queue<TreeNode*> todo;
        todo.push(root);
        int count = 0;
        while (!todo.empty())
        {
            int size = todo.size();
            count++;
            for (int i = 0; i < size; i++)
            {
                root = todo.front();
                todo.pop();
                if (root->left)
                    todo.push(root->left);
                if (root->right)
                    todo.push(root->right);
            }
        }
        return count;
    }
};


// Approahc 2 : Recursive 1
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return left > right ? left + 1 : right + 1;
    }
};

// Approahc 2 : Recursive 2
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root)
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        return 0;
    }
};


