/*
 130. Surrounded Regions (M)

 Approach 1 : BFS
 Flip the nodes that is not surrounded by 'X' to 'C', flip the nodes that is
 surrounded by 'X' to 'X'. And then, flip 'C' to 'O'
 Time: O(m*n)
 Space: O(1)

*/

/* Approach 1 */
class Solution {
    public void solve(char[][] board) {
        if (board.length == 0) return;
        
        int m = board.length;
        int n = board[0].length;

        // Start BFS from the edges of board
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    BFS(board, i, j);
                }
            }
        }
        
        // Flip back the nodes that is not surrounded by 'X'
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == 'C') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
    
    public void BFS(char[][] board, int i, int j) {
        if (i < 0 || j < 0 || i >= board.length || j >= board[0].length || board[i][j] == 'X' || board[i][j] == 'C')
            return;
        
        // Set sign to C to record not surrounded by X
        board[i][j] = 'C';
        
        // BFS the surrounded nodes
        BFS(board, i - 1, j);
        BFS(board, i + 1, j);
        BFS(board, i, j - 1);
        BFS(board, i, j + 1);
    }
}