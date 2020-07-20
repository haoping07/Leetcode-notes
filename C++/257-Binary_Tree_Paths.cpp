/*
 257. Binary Tree Paths (E)

 Preorder (top-down)
 Check left and right child, if exist, add the path string and move to it.
 T:O(n)
 S:O(n + leaf); n: Two queues for all nodes; leaf: vector for answer

 Postorder (btm-up)
 Start from the leaf, gather all its left and right path plus itself and 
 return upward 
 T:O(depth * n); Iterate all nodes record in each depth
 S:O(3n); Three vecotors for all left, right child and answer

*/

// Preorder (top-down)
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        vector<string> ret;
        // Queues for todo node and the current path 
        queue<TreeNode*> todo;
        queue<string> paths;
        todo.push(root);
        paths.push(to_string(root->val));
        
        while (!todo.empty()) {
            root = todo.front();
            todo.pop();
            string path = paths.front();
            paths.pop();
            if (root->left) {
                todo.push(root->left);
                paths.push(path + "->" + to_string(root->left->val));
            }
            if (root->right) {
                todo.push(root->right);
                paths.push(path + "->" + to_string(root->right->val));
            }
            if (!root->left && !root->right) {
                ret.push_back(path);
            }
        }
        return ret;
    }
};

// Postorder (btm-up)
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        vector<string> l, r, paths;
        // Get left and right paths
        l = binaryTreePaths(root->left);
        r = binaryTreePaths(root->right);

        // Add current node to the paths
        for (string& s : l) paths.push_back(to_string(root->val) + "->" + s);
        for (string& s : r) paths.push_back(to_string(root->val) + "->" + s);
        
        // If the nodes is a leaf, add the current node only
        if (l.size() == 0 && r.size() == 0) paths.push_back(to_string(root->val));

        return paths;
    }
};
