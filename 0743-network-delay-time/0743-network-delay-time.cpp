class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, list<pair<int, int>>> adj;
        for(int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back({v, w});
        }

        vector<int> distance(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        distance[k] = 0;
        while(!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            for(auto node: adj[u]) {
                int v = node.first;
                int wt = node.second;
                if(distance[v] > distance[u] + wt) {
                    distance[v] = distance[u] + wt;
                    pq.push({distance[v], v});
                }
            }
        }

        int maxi = INT_MIN; 
        for(int i = 1; i <= n; i++) {
            if(distance[i] == INT_MAX)
                return -1;
            maxi = max(maxi, distance[i]);
        }
        return maxi;
    }
};