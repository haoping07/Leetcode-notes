/*
 133. Clone Graph (M)

 Approach 1 : BFS
 Use map to store the origin (key) and cloned (value) nodes.
 Time: O(n)
 Space: O(n)

*/

/* Approach 1 */
class Solution {
    public Node cloneGraph(Node node) {
        if (node == null) return node;
 
        // Create map
        Map<Node, Node> map = new HashMap<>();
        // Build first node
        map.put(node, new Node(node.val));
        // DFS its neighbors
        DFS(node, map);
        
        return map.get(node);
    }
    
    public void DFS(Node node, Map<Node, Node> map) {
        // Iterate all neighbors in node
        for (Node n : node.neighbors) {
            // If the neighbors haven't created before
            if (map.get(n) == null) {
                // Create it and DFS it
                map.put(n, new Node(n.val));
                DFS(n, map);
            }
            // Add created neighbors to current created node's neighbors
            map.get(node).neighbors.add(map.get(n));
        }
    }
}
