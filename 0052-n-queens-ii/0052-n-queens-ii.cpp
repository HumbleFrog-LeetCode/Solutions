class Solution {
public:

    void generateOutput(vector<vector<string>> &res, vector<vector<int>> &board, int n) {
        vector<string> output;
        for(int i = 0; i < n; i++) {
            string ans = "";
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 0)
                    ans += ".";
                else
                    ans += "Q"; 
            }
            output.push_back(ans);
        }
        res.push_back(output);
    }

    bool isSafe(int row, int col, vector<vector<int>> &board, int n) {
        int x = row, y = col;
        while(y >= 0) {
            if(board[x][y])
                return false;
            y--;
        }

        x = row, y = col;
        while(x >= 0 && y >= 0) {
            if(board[x][y])
                return false;
            x--;    
            y--;
        }

        x = row, y = col;
        while(x < n && y >= 0) {
            if(board[x][y])
                return false;
            x++;    
            y--;
        }

        return true;
    }

    void solve(vector<vector<string>> &res, vector<vector<int>> &board, int col, int n) {
        if(col == n) {
            generateOutput(res, board, n);
            return;
        }

        for(int row = 0; row < n; row++) {
            if(isSafe(row, col, board, n)) {
                board[row][col] = 1;
                solve(res, board, col+1, n);
                board[row][col] = 0;
            }
        }
    }
    
    int totalNQueens(int n) {
        vector<vector<string>> res;
        vector<vector<int>> board(n, vector<int>(n, 0));
        solve(res, board, 0, n);
        return res.size();
    }
};