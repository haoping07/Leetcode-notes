/*
 200. Number of Islands (M)

 Notes:
	When encounter a need to see nodes around a node, we can pre-defined a 'directions' array (see line 18)
	Scan the array, if the value is '1', then use BFS to iterate its neighbors. The total island
	number is the number of times BFS operated.
	  T: O(4 * row * col)
	  S: O(n)
*/

// Approach 1
class Solution {
public:
    const int dx[4] = { 1, 0, -1, 0 };
    const int dy[4] = { 0, 1, 0, -1 };

    class Position
    {
    public:
        int row;
        int col;
    };

    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        int island = 0;
        for (int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[0].size(); col++)
            {
                if (grid[row][col] == '1')
                {
                    BFS(grid, row, col);
                    island++;
                }
            }
        }
        return island;
    }

    void BFS(vector<vector<char>>& grid, int row, int col)
    {
        Position pos, pos_next;
        pos.row = row;
        pos.col = col;
        queue<Position> todo;
        todo.push(pos);
        grid[row][col] = '0';
        while (!todo.empty())
        {
            pos = todo.front();
            todo.pop();

            for (int i = 0; i < 4; i++)
            {
                pos_next.row = pos.row + dy[i];
                pos_next.col = pos.col + dx[i];

                if (pos_next.row >= 0 && pos_next.row < grid.size() && pos_next.col >= 0 && pos_next.col < grid[0].size() && grid[pos_next.row][pos_next.col] == '1')
                {
                    grid[pos_next.row][pos_next.col] = '0';
                    todo.push(pos_next);
                }
            }
        }
    }
};

// Approach 2
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int X = grid.size();
		if (X == 0) return 0;
		int Y = grid[0].size();
		if (Y == 0) return 0;

		vector<vector<int>> directions = { {1,0}, {-1,0}, {0,1}, {0,-1} };
		vector<vector<bool>> visited(X, vector<bool>(Y, false));
		queue<vector<int>> Q;
		int nx = 0, ny = 0, island = 0;

		for (int x = 0; x < X; x++)
		{
			for (int y = 0; y < Y; y++)
			{
				if (grid[x][y] == '1' && visited[x][y] == false)
				{
					Q.push({ x,y });
					visited[x][y] = true;

					while (!Q.empty())
					{
						auto tmp = Q.front();
						Q.pop();

						for (int i = 0; i < 4; i++)
						{
							nx = tmp[0] + directions[i][0];
							ny = tmp[1] + directions[i][1];

							if (nx >= 0 && nx < X && ny >= 0 && ny < Y)
							{
								if (grid[nx][ny] == '1' && visited[nx][ny] == false)
								{
									Q.push({ nx,ny });
									visited[nx][ny] = true;
								}
							}
						}
					}
					island++;
				}
			}
		}
		return island;
	}
};