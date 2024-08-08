class Solution {
public:

    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        // Prepare adjacency list
        priority_queue<pair<int, int>> adj[n]; // (u, w, v)
        for(int i = 0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wu = vals[u];
            int wv = vals[v];
            adj[u].push({wv, v});
            adj[v].push({wu, u});
        }
        
        int sum = 0, count = 1, maxi = INT_MIN;
        for(int i=0; i<n; i++) {
            sum = vals[i];
            while(!adj[i].empty() && count <= k) {
                count++;
                if(sum + adj[i].top().first > sum) {
                    sum += adj[i].top().first;
                    adj[i].pop();
                }
            }
            maxi = max(maxi, sum);
            sum = 0;
            count = 1;
        }
        return maxi;
    }
};