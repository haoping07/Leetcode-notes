/*
 102. Binary Tree Level Order Traversal (M)

 A1: BFS
 Before each level: the number of node in queue is the number of node in that level.
 In each level: push the left and right child into queue, if any.
 After each level: push the vector that contains all nodes in that level into result vector.
 Time: O(n)
 Space: O(n)

 A2: DFS
 If the depth of the current node is greater than the result vector size, push_back a 
 vector contains current node's value. Else, put the current node's value into the
 corresponding index of result vector.
 [Imagine this method as 'fill the stairs']
 Time: O(n)
 Space: O(n)

*/

// A1
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> todo;
        vector<vector<int>> res;
        todo.push(root);
        while (!todo.empty()) {
            int size = todo.size();
            vector<int> sub;
            for (int i = 0; i < size; i++) {
                root = todo.front();
                todo.pop();
                sub.push_back(root->val);
                if (root->left) todo.push(root->left);
                if (root->right) todo.push(root->right);
            }
            res.push_back(sub);
        }
        return res;
    }
};

// A2
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        DFS(root, 1, res);
        return res;
    }
    
    void DFS(TreeNode* root, int depth, vector<vector<int>>& res) {
        if (!root) return;
        if (res.size() < depth) res.push_back({root->val});
        else res[depth - 1].push_back(root->val);
        DFS(root->left, depth + 1, res);
        DFS(root->right, depth + 1, res);
    }
};