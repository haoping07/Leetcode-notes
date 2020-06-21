/*
 257. Binary Tree Paths (E)

 A1: Preorder(top-down)
 Check the left and right child, if exist, add the path string and move to it.
 Time: O(n)
 Space: O(leaf)

 A2: Preorder(down-top)
 Start from the leaf, gather all its left and right path plus itself and 
 return upward 
 Time: O(n);
 Space: O(n)

*/

// A1
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        vector<string> res;

        // Queue for the to-do nodes
        queue<TreeNode*> todo;
        // Queue for the path strings
        queue<string> paths;

        // Init the algo
        todo.push(root);
        paths.push(to_string(root->val));

        while (!todo.empty()) {
            root = todo.front();
            todo.pop();
            string path = paths.front();
            paths.pop();
            
            // If the left child exist, add the path and to-do node
            if (root->left) {
                paths.push(path + "->" + to_string(root->left->val));
                todo.push(root->left);
            }
            // So does the right child
            if (root->right) {
                paths.push(path + "->" + to_string(root->right->val));
                todo.push(root->right);
            }
            // If the leaf node, save the path to the result
            if (!root->left && !root->right) {
                res.push_back(path);
            }
        }
        return res;
    }
};


// A2
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        vector<string> l, r, paths;

        // Gather all left paths
        l = binaryTreePaths(root->left);

        // Gather all right paths
        r = binaryTreePaths(root->right);

        // Add the current node to the paths
        for (string& s : l) paths.push_back(to_string(root->val) + "->" + s);
        for (string& s : r) paths.push_back(to_string(root->val) + "->" + s);

        // If the nodes is a leaf, just add the current node only
        if (l.size() == 0 && r.size() == 0) paths.push_back(to_string(root->val));

        return paths;
    }
};