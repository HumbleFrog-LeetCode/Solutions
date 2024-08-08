class Solution {
public:

    void dfs(vector<vector<int>>& grid, vector<vector<int>> &visited, int x, int y, int m, int n) {
        if(x>=0 && x<m && y>=0 && y<n && grid[x][y] == 1 && visited[x][y] != 1)
            visited[x][y] = 1;
        else 
            return;
        dfs(grid, visited, x+1, y, m, n);
        dfs(grid, visited, x-1, y, m, n);
        dfs(grid, visited, x, y+1, m, n);
        dfs(grid, visited, x, y-1, m, n);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if((i == 0 || i == m-1 || j == 0 || j == n-1) && grid[i][j] == 1 && !visited[i][j])
                    dfs(grid, visited, i, j, m, n);
            }
        }

        int count = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                    count += (grid[i][j] == 1 && visited[i][j] == 0);
    
        return count;
    }
};