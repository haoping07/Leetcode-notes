/*
 207. Course Schedule
 Medium
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph = vector<vector<int>>(numCourses);
        vector<int> status(numCourses, 0);
        for (const auto& p : prerequisites)
            graph[p[0]].push_back(p[1]);
 
        for (int i = 0; i < numCourses; i++)
        {
            if (DFS(i, status))
                return false;
        }
        return true;
    }
 
    bool DFS(int cur, vector<int>& status)
    {
        if (status[cur] == 1)
            return true;
        if (status[cur] == 2)
            return false;
 
        status[cur] = 1;
 
        for (const auto& neighbor : graph[cur])
        {
            if (DFS(neighbor, status))
                return true;
        }
 
        status[cur] = 2;
 
        return false;
    }        
 
 
private:
    vector<vector<int>> graph;
};
