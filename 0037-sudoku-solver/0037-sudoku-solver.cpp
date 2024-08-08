class Solution {
public:

    bool isSafe(vector<vector<char>>& board, int i, int j, int n, int c) {
        for(int k = 0; k < n; k++) {
            if(board[i][k] == c) return false;
            if(board[k][j] == c) return false;
            if(board[3 * (i/3) + k/3][3 * (j/3) + k%3] == c) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        int n = board.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == '.') {
                    for(char c = '1'; c <= '9'; c++) {
                        if(isSafe(board, i, j, n, c)) {
                            board[i][j] = c;
                            if(solve(board))
                                return true;
                            else
                                board[i][j] = '.';
                        }    
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};