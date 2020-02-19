/*
 310. Minimum Height Trees (M)

 Notes:
    1. Build graph and count the indegree of each node
    2. If indegree is 1, which is a leaf, push into a queue, and make it "visited"
    3. BFS the nodes in queue
      3.1. Cut the node which is record as "visited" yet
      3.2. If indegree becomes one after the cut, pushes it into queue and mark it "visited" 
    The nodes which is/are processed in the last BFS round (at most 2 nodes) is/are the answer
      T: O(n)? n nodes to cut?
      S: O(V + 2E)? Need to store whole tree?
*/

// *Approach 1 : Ref from https://www.jiuzhang.com/solution/minimum-height-trees/#tag-other-lang-cpp
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 0 || n == 1) return { 0 };
        vector<int> indegree(n, 0);
        vector<vector<int>> outdegree(n, vector<int>());

        // Build graph
        for (int i = 0; i < edges.size(); i++)
        {
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
            outdegree[edges[i][0]].push_back(edges[i][1]);
            outdegree[edges[i][1]].push_back(edges[i][0]);
        }

        queue<int> todo;
        unordered_set<int> visited;

        // Push indegree = 1 node to queue
        for (int i = 0; i < indegree.size(); i++)
        {
            if (indegree[i] == 1)
            {
                todo.push(i);
                visited.insert(i);
            }
        }

        vector<int> ans;

        // BFS
        while (!todo.empty())
        {
            ans.clear();
            int size = todo.size();
            for (int i = 0; i < size; i++)
            {
                int node = todo.front();
                todo.pop();
                ans.push_back(node);
                for (int j = 0; j < outdegree[node].size(); j++)
                {
                    int sub = outdegree[node][j];
                    if (visited.find(sub) != visited.end())
                        continue;
                    indegree[sub]--;

                    if (indegree[sub] == 1)
                    {
                        todo.push(sub);
                        visited.insert(sub);
                    }
                }
            }
        }
        return ans;
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

