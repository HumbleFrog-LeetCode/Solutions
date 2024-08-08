class Solution {
public:

    void dfs(int node, unordered_map<int, list<int>> &adj, vector<bool> &visited) {
        visited[node] = true;
        for(auto nbr: adj[node])
            if(!visited[nbr])
                dfs(nbr, adj, visited);
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, list<int>> adj;
        for(int i = 0; i<prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
        }

        vector<bool> visited(numCourses, 0);
        vector<bool> res;
        stack<int> s;

        for(int i = 0; i<queries.size(); i++) {
            int u = queries[i][0];
            int v = queries[i][1];
            if(u == v)
                res.push_back(false);
            else {
                dfs(u, adj, visited);
                res.push_back(visited[v]);
                for(auto x: visited)
                    x = false;
            }  
        }
        return res;
    }
};