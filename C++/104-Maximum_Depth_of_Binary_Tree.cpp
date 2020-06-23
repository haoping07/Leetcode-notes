/*
 104. Maximum Depth of Binary Tree (E)
 
 A1: DFS(top-down); A1-2: DFS(btm-up); A1-3: DFS (btm-up) 
 Time: O(n)
 Space: O(n)

 A2: BFS (top-down)
 Time: O(n)
 Space: O(n)

*/

// A1
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int res = 0;
        DFS(root, 0, res);
        return res;
    }
    
    void DFS(TreeNode* root, int curMax, int& totalMax) {
        if (!root) return;
        curMax++;
        if (!root->left && !root->right) {
            totalMax = max(totalMax, curMax);
            return;
        }
        
        if (root->left) DFS(root->left, curMax, totalMax);
        if (root->right) DFS(root->right, curMax, totalMax);
    }
};

// A1-2
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

// A1-3
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return left > right ? left + 1 : right + 1;
    }
};


// A2
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
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
                if (root->left) todo.push(root->left);
                if (root->right) todo.push(root->right);
            }
        }
        return count;
    }
};
