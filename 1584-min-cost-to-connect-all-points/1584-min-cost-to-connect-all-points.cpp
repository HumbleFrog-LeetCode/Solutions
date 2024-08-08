#include<bits/stdc++.h>
class Solution {
public:

    void makeSet(vector<int> &parent, vector<int> &rank, int n) {
        for(int i=0; i<n; i++) {
            parent[i] = i;
            rank[i] = 0; 
        }
    }

    int findParent(vector<int> &parent, int u) {
        if(parent[u] == u)
            return u;
        return parent[u] = findParent(parent, parent[u]);    
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

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> edges;
        for(int i = 0; i<n-1; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j = i+1; j<n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int w = abs(x1-x2) + abs(y1-y2);
                edges.push_back({i, j, w});
            }
        }

        vector<int> parent(n);
        vector<int> rank(n);
        makeSet(parent, rank, n);
        int minWeight = 0;
        sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b) {
            return a[2] < b[2];
        });

        for(int i = 0; i<edges.size(); i++) {
            int u = findParent(parent, edges[i][0]);
            int v = findParent(parent, edges[i][1]);
            int w = edges[i][2];
            if(u != v) {
                unionSet(parent, rank, u, v);
                minWeight += w;
            }
        }
        return minWeight;
    }
};