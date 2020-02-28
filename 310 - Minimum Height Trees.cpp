/*
 310. Minimum Height Trees (M)

 Notes:
 Approach 1 : Graph
 Ref(https://www.jiuzhang.com/solution/minimum-height-trees/#tag-other-lang-cpp)
 1. Build indegree, outdegree map
 2. Push indegree = 1 into queue and BFS it
 3. In each BFS round, decrement the node indegree which connects to this indegree = 1 node, if a 
    node indegree become 1, push it into queue
 The nodes which is/are processed in the last BFS round (at most 2 nodes) is/are the answer
 Time: O(n)? n nodes to cut?
 Space: O(n)? hashmap's space complexity is O(n)

 Approach 2 :

*/

// *Approach 1 : Graph
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 0 || n == 1 || edges.size() == 0)
            return { 0 };

        // Build indegree, outdegree map
        vector<int> indegree(n, 0);
        vector<vector<int>> outdegree(n, vector<int>());

        for (int i = 0; i < edges.size(); i++)
        {
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
            outdegree[edges[i][0]].push_back(edges[i][1]);
            outdegree[edges[i][1]].push_back(edges[i][0]);
        }

        // Push indegree = 1 into queue and BFS it
        queue<int> oneDegree;
        unordered_set<int> visited;

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 1)
            {
                oneDegree.push(i);
                visited.insert(i);
            }
        }

        // Each BFS round cut the node, if a node indegree become 1, push to queue
        vector<int> res;

        while (!oneDegree.empty())
        {
            res.clear();
            int size = oneDegree.size();
            for (int i = 0; i < size; i++)
            {
                int n = oneDegree.front();
                oneDegree.pop();
                res.push_back(n);
                for (int neighbor : outdegree[n])
                {
                    if (visited.find(neighbor) != visited.end())
                        continue;
                    indegree[neighbor]--;

                    if (indegree[neighbor] == 1)
                        oneDegree.push(neighbor);
                }
            }
        }
        return res;
    }
};


// Approach 2 : 
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> map;
        for (vector<int> edge : edges)
        {
            int a = edge[0], b = edge[1];
            map[a].insert(b);
            map[b].insert(a);
        }

        queue<int> leaf;
        for (int i = 0; i < n; i++)
        {
            if (map[i].size() == 1)
                leaf.push(i);
        }

        // unorderd_set::erase T: O(1)
        unordered_set<int> visit;
        for (int i = 0; i < n; i++)
            visit.insert(i);

        while (visit.size() > 2)
        {
            int size = leaf.size();
            for (int i = 0; i < size; i++)
            {
                int cur = leaf.front();
                leaf.pop();
                visit.erase(cur);

                for (auto next : map[cur])
                {
                    map[next].erase(cur);
                    if (map[next].size() == 1)
                        leaf.push(next);
                }
            }
        }

        vector<int> result;
        for (auto c : visit)
            result.push_back(c);
        return result;
    }
};

