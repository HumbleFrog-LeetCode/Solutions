class Solution {
public:

    void makeSet(vector<int> &parent, vector<int> &rank, int n) {
        for(int i= 0; i<n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int findParent(vector<int> &parent, int node) {
        if(parent[node] == node)
            return node;
        return parent[node] = findParent(parent, parent[node]);    
    }

    void unionSet(vector<int> &parent, vector<int> &rank, int u, int v) {
        u = findParent(parent, u);
        v = findParent(parent, v);

        if(rank[u] < rank[v])
            parent[u] = v;
        else if(rank[u] > rank[v])
            parent[v] = u;
        else {
            parent[v] = u;
            rank[u]++;
        }        
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        vector<int> rank(n+1);
        makeSet(parent, rank, n);
        vector<vector<int>> ans;

        for(int i = 0; i<n; i++) {
            int u = findParent(parent, edges[i][0]);
            int v = findParent(parent, edges[i][1]);

            if(u == v)
                ans.push_back(edges[i]); 
            else     
                unionSet(parent, rank, u, v);    
        }

        return ans.back();
    }
};