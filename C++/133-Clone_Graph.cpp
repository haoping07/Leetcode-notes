/*
 133. Clone Graph (M)

 Notes:
 Approach 1 : Hashmap + DFS
 Build graph with key are original node and value are copied node. Use DFS to traverse the original nodes and link
 the copied nodes neighbors.
 Time: O(V + E), E: enter neighbors to check if visited
 Space: O(V)

*/

// Approach 1 : Hashmap + DFS
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> map;
        map[node] = new Node(node->val);
        DFS(node, map);
        return map[node];
    }

    void DFS(Node* node, unordered_map<Node*, Node*>& map)
    {
        for (const auto& neighbor : node->neighbors)
        {
            if (map.find(neighbor) == map.end())
            {
                map[neighbor] = new Node(neighbor->val);
                DFS(neighbor, map);
            }
            map[node]->neighbors.push_back(map[neighbor]);
        }
    }
};