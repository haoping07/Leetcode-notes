/*
 130. Surrounded Regions (M)

 Notes:
	* When encounter a need to see nodes around a node, we can pre-defined 'directions' 
	  array (see line 15, 16)
	* 'Inside out' BFS is ok but needs extra space to record traversed elements and flip
	  them if BFS end in edge.
	* Use 'Outside in' BFS from the edge element that is not 'X', traverses and flips the 
	  elements to 'V' temporary. At the end, flips all remains 'O' to 'X' and 'V' to 'O'
*/

class Solution {
private:
	int xdir[4] = { 1, -1, 0, 0 };
	int ydir[4] = { 0, 0, 1, -1 };

public:
	void BFS(vector<vector<char>>& board, int x, int y)
	{
		queue<vector<int>> Q;
		Q.push({ x, y });
		board[x][y] = 'V';
		int nx = 0, ny = 0;

		while (!Q.empty())
		{
			auto tmp = Q.front();
			Q.pop();
			for (int i = 0; i < 4; i++)
			{
				nx = tmp[0] + xdir[i];
				ny = tmp[1] + ydir[i];

				if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size())
				{
					if (board[nx][ny] == 'O')
					{
						board[nx][ny] = 'V';
						Q.push({ nx, ny });
					}
				}
			}
		}
	}

	void solve(vector<vector<char>>& board) {
		for (int x = 0; x < board.size(); x++)
		{
			for (int y = 0; y < board[0].size(); y++)
			{
				if (x != 0 && x != board.size() - 1 && y != 0 && y != board[0].size() - 1)
					continue;
				if (board[x][y] == 'O')
					BFS(board, x, y);
			}
		}

		for (int x = 0; x < board.size(); x++)
		{
			for (int y = 0; y < board[0].size(); y++)
			{
				if (board[x][y] == 'V')
					board[x][y] = 'O';
				else if (board[x][y] == 'O')
					board[x][y] = 'X';
			}
		}
	}
};