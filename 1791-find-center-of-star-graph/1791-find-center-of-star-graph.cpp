class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // Prepare adjacency list
        unordered_map<int, list<int>> adj;
        for(int i = 0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int vertices = adj.size();

        // Find indegree of each node
        unordered_map<int, int> indegree;
        for(auto i: adj)
            for(auto j: i.second)
                indegree[j]++;

        for(auto x: indegree)
            if(x.second == vertices - 1)
                return x.first;
                
        return -1;        
    }
};