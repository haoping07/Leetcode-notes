/*
 210. Course Schedule II (M)

 Notes:
    Ref. 207
 
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        graph = vector<vector<int>>(numCourses);
        for (const auto& p : prerequisites)
            graph[p[0]].push_back(p[1]);
        vector<int> status(numCourses, 0);
        for (int i = 0; i < numCourses; i++)
        {
            if (DFS(i, status, result))
                return {};
        }
 
        return result; 
    }
 
    bool DFS(int node, vector<int>& status, vector<int>& result)
    {
        if (status[node] == 2)
            return false;
        if (status[node] == 1)
            return true;
 
        status[node] = 1;
 
        for (const int neighbor : graph[node])
        {
            if (DFS(neighbor, status, result))
                return true;
        }
 
        status[node] = 2;
        result.push_back(node);
 
        return false;
    }
 
private:
    vector<vector<int>> graph;
};
