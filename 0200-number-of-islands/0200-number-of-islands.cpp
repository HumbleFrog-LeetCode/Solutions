class Solution {
public:

    void dfs(vector<vector<char>> &grid, vector<vector<int>> &visited, int x, int y, int m, int n) {
        if(x>=0 && x<m && y>=0 && y<n && visited[x][y] != 1 && grid[x][y] == '1')  
            visited[x][y] = 1;
        else
            return;    
        dfs(grid, visited, x+1, y, m, n);
        dfs(grid, visited, x-1, y, m, n);
        dfs(grid, visited, x, y+1, m, n);
        dfs(grid, visited, x, y-1, m, n);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    count++;
                    dfs(grid, visited, i, j, m, n);
                }
            }
        }
        return count;
    }
};