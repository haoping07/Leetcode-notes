/*
 200. Number of Islands (M)

 Approach 1 :
 Iterate all nodes, if the node is land, BFS and flip it to zero.
 Time: O(mn)
 Space: O(1)

*/

/* Approach 1 */
class Solution {
    public int numIslands(char[][] grid) {
        if (grid.length == 0) return 0;
        
        int m = grid.length;
        int n = grid[0].length;
        int c = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    c++;
                    BFS(grid, i, j);
                }
            }
        }
        return c;
    }
    
    public void BFS(char[][] grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.length || j >= grid[0].length || grid[i][j] == '0')
            return;
        
        // Set land to 0
        grid[i][j] = '0';
        
        // Go around the node
        BFS(grid, i - 1, j);
        BFS(grid, i + 1, j);
        BFS(grid, i, j - 1);
        BFS(grid, i, j + 1);
    }
}
