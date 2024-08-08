class Solution {
public:

    void bfs(int node, unordered_map<int, list<int>> &adj, int n, vector<vector<int>> &res) {
        vector<bool> visited(n, false);
        visited[node] = true;
        queue<int> q;
        q.push(node);

        while(!q.empty()) {
            int frontNode = q.front();
            q.pop();

            for(auto nbr: adj[frontNode]) {
                if(!visited[nbr]) {
                    visited[nbr] = true;
                    res[nbr].push_back(node); //  Be careful with this step
                    q.push(nbr);
                }
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int, list<int>> adj;
        for(int i = 0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }

        vector<vector<int>> res(n);
        for(int i = 0; i < n; i++)
            bfs(i, adj, n, res);
        return res;
    }
};