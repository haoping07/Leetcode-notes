/*
 173. Binary Search Tree Iterator (M)

 Notes:
 Approach 1 : DFS (Inorder) to vector
 DFS (inorder) to a vector, the next() will return the vector one by one.
 Time: O(1) for next() 
 Space: O(n)

 Approach 2 : DFS to Stack
 Push leftmost nodes to stack, then do the inorder traversal
 Time: O(n)
 Space: O(n)

*/

// Approach 1 :
class BSTIterator {
private:
    vector<int> nodes;
    int cur;
    int size;
public:
    BSTIterator(TreeNode* root) {
        DFS(root);
        cur = 0;
        size = nodes.size();
    }

    /** @return the next smallest number */
    int next() {
        return nodes[cur++];
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return cur < size;
    }

    void DFS(TreeNode* root)
    {
        if (!root) return;
        DFS(root->left);
        nodes.push_back(root->val);
        DFS(root->right);
    }
};


// Approach 2 :
class BSTIterator {
private:
    stack<TreeNode*> st;

public:
    BSTIterator(TreeNode* root) {
        while (root)
        {
            st.push(root);
            root = root->left;
        }
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* node = st.top();
        st.pop();
        TreeNode* cur = node->right;
        while (cur)
        {
            st.push(cur);
            cur = cur->left;
        }
        return node->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }
};