/*
 310. Minimum Height Trees
 Medium
*/

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
