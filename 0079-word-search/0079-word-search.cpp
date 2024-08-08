class Solution {
public:

    bool solve(int x, int y, int m, int n, int index, vector<vector<char>>& board, string &word) {
        if(index >= word.size())
            return true;
        if(x < 0 || x >= m || y < 0 || y >= n || board[x][y] != word[index])
            return false;

        char temp = board[x][y];
        board[x][y] = '.';

        bool ans = solve(x+1, y, m, n, index+1, board, word) ||  
                   solve(x-1, y, m, n, index+1, board, word) ||  
                   solve(x, y+1, m, n, index+1, board, word) ||  
                   solve(x, y-1, m, n, index+1, board, word);  
        board[x][y] = temp;
        return ans;               
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0] && solve(i, j, m, n, 0, board, word))
                    return true;
            }
        }
        return false;
    }
};