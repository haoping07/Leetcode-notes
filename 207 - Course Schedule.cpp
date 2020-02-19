/*
 207. Course Schedule (M)

 Notes:
    If cycle exist in graph, it is impossible to finish all courses.
    Approach 1 : DFS
    1. Build graph
    2. Create status map and init to 0 for each node (0: unseen, 1: in DFS process, 2: finished DFS process)
    3. DFS each nodes
      3.1. Check status. If 1, return true (have cycle). If 2, return true (visited, ok node)
      3.2. If unseen, set status to 1 and DFS its neighbors
    4. If no cycle, all courses can be finished
    T: O(n), traverse all nodes
    S: O(n), status map

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