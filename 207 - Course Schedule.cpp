/*
 207. Course Schedule (M)
 
 Notes:
    It is possible to finish all courses if 'cycle' exist.
    Approach 1 : DFS
     1. Build graph vector
     2. Create visited node vector
     3. Iterate all nodes
        0. If the node status is 1, cycle exist. Return fail
           If the node status is 2, cycle not exist from that node. Return ok
        1. Set status to 1
        2. Iterate its neighbors by DFS
        3. If all neighbors checked, set stauts to 2
        4. Return ok
    T: O(n)
    S: O(n)
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
        // 0 : 未探索
        // 1 : 正在探索
        // 2 : 該點下全鄰居探索完
        // 如果探索鄰居發現有人是1, 代表有迴圈, 不可能修完
        if (status[cur] == 1)
            return true;

        // 該鄰居以被探索過沒問題, 跳出
        if (status[cur] == 2)
            return false;
 
        status[cur] = 1;
 
        for (const auto& neighbor : graph[cur])
        {
            if (DFS(neighbor, status))
                return true;
        }
 
        status[cur] = 2;
        
        // 探索完全鄰居, 返回2表示探索完
        return false;
    }        
 
 
private:
    vector<vector<int>> graph;
};
