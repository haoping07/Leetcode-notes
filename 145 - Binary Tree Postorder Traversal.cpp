/*
 145. Binary Tree Postorder Traversal (Hard)

 Notes:
    Tree traversal - BFS, DFS. Use DFS here O(n)
    Four steps: left child, peek parent, right child, parent
    Step 1 -> Left child: Traverse to the end of the left child.
    Step 2 -> Peek parent: We need to access right child before parent node so we traverse to 
                           right child by 'peeking' parent node then access its right child.
    Step 3 -> right child: If right child have children, run step 1 ~ 4 on it;
    Step 4 -> After visited right child, now it is time to access parent
*/

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> todo;
        TreeNode* visited = nullptr;

        while (!todo.empty() || root)
        {
            while (root)
            {
                todo.push(root);
                root = root->left;
            }

            TreeNode* peekNode = todo.top();
            if (peekNode->right && peekNode->right != visited)
                root = peekNode->right;
            else
            {
                res.push_back(peekNode->val);
                todo.pop();
                visited = peekNode;
            }
        }
        return res;
    }
};