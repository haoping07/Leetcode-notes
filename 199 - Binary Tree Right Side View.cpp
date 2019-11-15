/*
 199. Binary Tree Right Side View (Medium)

*/

// Recursive DFS 
class Solution {
public:
	vector<int> res;

	void DFS(TreeNode* root, int depth)
	{
		if (!root) return;
		if (depth > res.size())
			res.push_back(root->val);
		DFS(root->left, depth + 1);
		DFS(root->right, depth + 1);
		res[depth - 1] = root->val;
	}

	vector<int> rightSideView(TreeNode* root) {
		DFS(root, 1);
		return res;
	}
};

// Iterative BFS
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> result;
        queue<TreeNode*> todo;
        todo.push(root);
        while (!todo.empty())
        {
            int size = todo.size();
            for (int i = 0; i < size; i++)
            {
                root = todo.front();
                todo.pop();
                if (root->left)
                    todo.push(root->left);
                if (root->right)
                    todo.push(root->right);
                if (i == size - 1)
                    result.push_back(root->val);
            }
        }
        return result;
    }
};