class Solution {
public:

    void dfs(vector<vector<char>>& board, vector<vector<int>>& visited, int x, int y, int m, int n, char ch) {
        if(x>=0 && x<m && y>=0 && y<n && board[x][y] == 'O' && !visited[x][y]) {
            board[x][y] = ch;
            visited[x][y] = 1;
        }
        else
            return;
        dfs(board, visited, x+1, y, m, n, ch);
        dfs(board, visited, x-1, y, m, n, ch);
        dfs(board, visited, x, y+1, m, n, ch);
        dfs(board, visited, x, y-1, m, n, ch);
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if((i == 0 || i == m-1 || j == 0 || j == n-1) && board[i][j] == 'O')
                    dfs(board, visited, i, j, m, n, '-');
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O')
                    dfs(board, visited, i, j, m, n, 'X');
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == '-')
                    board[i][j] = 'O';
            }
        }
    }
};
