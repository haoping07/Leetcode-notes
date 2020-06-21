/*
 207. Course Schedule (M)

 Notes:
 If cycle exist in graph, it is impossible to finish all courses.

 Approach 1 : DFS
 1. Build graph
 2. DFS the graph to check if cycle exist
 Time: O(n), traverse all nodes
 Space: O(n), status map and graph

*/

// *Approach 1 : DFS
class Solution {
private:
    vector<vector<int>> graph;
    vector<int> status;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph = vector<vector<int>>(numCourses, vector<int>());
        status = vector<int>(numCourses, 0);

        // Build graph
        for (const vector<int>& p : prerequisites)
            graph[p[0]].push_back(p[1]);

        // BFS the graph (to check if cycle exist)
        for (int i = 0; i < numCourses; i++)
        {
            if (DFS(i))
                return false;
        }
        return true;
    }

    bool DFS(int cur)
    {
        // If cur is still in DFS process
        if (status[cur] == 1)
            return true;

        // If cur was finished DFS process beforehand
        if (status[cur] == 2)
            return false;

        // Set status to 1 (In DFS process) and start DFS
        status[cur] = 1;

        for (const int& neighbor : graph[cur])
        {
            if (DFS(neighbor))
                return true;
        }

        // Set status to 2 (Finish DFS process)
        status[cur] = 2;
        return false;
    }
};