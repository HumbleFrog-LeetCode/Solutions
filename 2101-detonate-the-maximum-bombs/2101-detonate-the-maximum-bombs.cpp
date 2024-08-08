class Solution {
public:

    void dfs(int node, vector<bool> &visited, unordered_map<int, list<int>> &adj) {
        visited[node] = true;
        for(auto nbr: adj[node])
            if(!visited[nbr])
                dfs(nbr, visited, adj);
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        unordered_map<int, list<int>> adj;
        vector<bool> visited(n, false);
        for(int i = 0; i < n-1; i++) {
            for(int j = i + 1; j < n; j++) {
                long long x1 = bombs[i][0], x2 = bombs[j][0];
                long long y1 = bombs[i][1], y2 = bombs[j][1];
                long long r1 = 1LL * bombs[i][2] * bombs[i][2], r2 = 1LL * bombs[j][2] * bombs[j][2];
                long long d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
                if(d <= r1)
                    adj[i].push_back(j);
                if(d <= r2)
                    adj[j].push_back(i);    
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            visited.clear();
            visited.resize(n, false);
            dfs(i, visited, adj);
            int count = 0;
            for(auto x: visited)
                count += (x == true);
            ans = max(ans, count);       
        }
        return ans;
    }
};