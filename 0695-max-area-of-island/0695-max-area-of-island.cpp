class Solution {
public:


    int dfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int x, int y, int m, int n, int &c) {
        if(x>=0 && x<m && y>=0 && y<n && grid[x][y] == 1 && !visited[x][y]) {
            c++;
            visited[x][y] = 1;
        } 
        else 
            return 0;

        dfs(grid, visited, x+1, y, m, n, c);
        dfs(grid, visited, x-1, y, m, n, c);
        dfs(grid, visited, x, y+1, m, n, c);
        dfs(grid, visited, x, y-1, m, n, c);

        return c;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxi = 0;

        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j ++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    int c = 0;
                    int area = dfs(grid, visited, i, j, m, n, c);
                    maxi = max(maxi, area);
                }
            }
        }
        return maxi;
    }
};