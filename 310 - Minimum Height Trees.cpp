/*
 310. Minimum Height Trees (M)
 
 Notes:
    1. Build graph
    2. Count indegree of each node
    3. Push nodes which indegree == 1 to queue
    4. Find the root of each node in queue, decreae 1
    5. If root node's indegree == 1, push it to queue
    The last / remaining nodes (at most 2 nodes) will be the answer.
     T: O(e + 3n)?
     S: O(n)?
*/

// Approach 1 : 
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

// Approach 2 : Ans from https://www.jiuzhang.com/solution/minimum-height-trees/#tag-other-lang-cpp
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 0 || n == 1) return { 0 };
        vector<int> indegree(n, 0);
        vector<vector<int>> outdegree(n, vector<int>(0));

        for (int i = 0; i < edges.size(); i++)
        {
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
            outdegree[edges[i][0]].push_back(edges[i][1]);
            outdegree[edges[i][1]].push_back(edges[i][0]);
        }

        queue<int> todo;
        unordered_set<int> visited;

        for (int i = 0; i < indegree.size(); i++)
        {
            if (indegree[i] == 1)
            {
                todo.push(i);
                visited.insert(i);
            }
        }

        vector<int> ans;

        while (!todo.empty())
        {
            ans.clear();
            int size = todo.size();
            for (int i = 0; i < size; i++)
            {
                int cur = todo.front();
                todo.pop();
                ans.push_back(cur);
                for (int j = 0; j < outdegree[cur].size(); j++)
                {
                    int sub = outdegree[cur][j];
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