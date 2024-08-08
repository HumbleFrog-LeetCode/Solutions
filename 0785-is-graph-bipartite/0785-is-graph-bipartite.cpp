class Solution {
public:

    bool bfs(int node, unordered_map<int, list<int>> &adj, vector<int> &color) {
        queue<int> q;
        q.push(node);
        color[node] = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto nbr: adj[node]) {
                if(color[nbr] == -1) {
                    color[nbr] = !color[node];
                    q.push(nbr);
                }
                else if(color[nbr] == color[node])
                    return false;    
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int, list<int>> adj;
        for(int i = 0; i<graph.size(); i++)
            for(auto x: graph[i])
                adj[i].push_back(x);

        int n = graph.size();
        vector<int> color(n, -1);
        for(int i = 0; i < n; i++)
            if(color[i] == -1)
                if(!bfs(i, adj, color))
                    return false;

        return true;
    }
};