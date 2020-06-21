/*
 297. Serialize and Deserialize Binary Tree (H)

 Notes:
 Approach 1 : DFS + Preorder
 Time: O(nodes)
 Space: O(string length)

 Approach 2 : BFS
 Time: O(nodes)
 Space: O(string length)

*/

/* Approach 1 : */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }

private:
    void serialize(TreeNode* root, ostringstream& out)
    {
        if (root)
        {
            out << root->val << " ";
            serialize(root->left, out);
            serialize(root->right, out);
        }
        else
            out << "# ";
    }

    TreeNode* deserialize(istringstream& in)
    {
        string val;
        in >> val;
        if (val == "#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};


/* Approach 2 : */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        string serial = "[";
        queue<TreeNode*> todo;
        todo.push(root);
        while (!todo.empty())
        {
            TreeNode* head = todo.front();
            todo.pop();
            if (head)
            {
                if (head != root)
                    serial += ",";
                serial += to_string(head->val);
                todo.push(head->left);
                todo.push(head->right);
            }
            else
                serial += ",#";
        }

        for (int i = serial.size() - 1; i >= 0; i--)
        {
            if (serial[i] == '#' || serial[i] == ',')
                serial.erase(i, 1);
            else break;
        }

        serial += "]";
        return serial;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode** ptr = new TreeNode*;
        *ptr = nullptr;
        queue<TreeNode**> todo;
        todo.push(ptr);
        for (int i = 1, val = 0, skip = 0, neg = 0; i < data.size(); i++)
        {
            if (data[i] == ',' || data[i] == ']')
            {
                if (skip)
                {
                    skip = 0;
                    continue;
                }
                TreeNode** p = todo.front();
                todo.pop();
                *p = new TreeNode(val);
                todo.push(&((*p)->left));
                todo.push(&((*p)->right));
                val = 0;
            }
            else if (data[i] == '-')
                neg = 1;
            else if (data[i] != '#')
            {
                val *= 10;
                val += (data[i] - '0');
                if (neg)
                {
                    neg = 0;
                    val *= -1;
                }
            }
            else if (data[i] == '#')
            {
                skip = 1;
                todo.pop();
            }

        }
        return *ptr;
    }
};


