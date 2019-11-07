/*
 200. Number of Islands (Medium)

 Notes:
	* When encounter a need to see nodes around a node, we can pre-defined a 'directions' array (see line 18)
	Scan the array, if the value is '1', then use BFS to iterate its neighbors. The total island
	number is the number of times BFS operated.
*/

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