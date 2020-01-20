/*
 133. Clone Graph (M)

 Notes:
    1. Build a hashmap used to store corresponding original node and clone node.
    2. DFS the node
       1. Iterate all its neighbors, if not yet existed in hashmap, create it, DFS it, and copy it 
          as neighbor to the clone node's neighbor list
    T: O(V + E)   // E: enter neighbors to check if visited
    S: O(V + E)
*/

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