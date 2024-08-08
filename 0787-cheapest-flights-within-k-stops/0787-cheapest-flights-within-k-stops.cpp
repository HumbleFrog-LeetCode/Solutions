class Solution {
public:

    typedef pair<int, pair<int, int>> pii; // stops (k), vertex (u), distance (w) 

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, list<pair<int, int>>> adj;
        for(int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            adj[u].push_back({v, w});
        }

        vector<int> distance(n, INT_MAX);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, {src, 0}});

        while(!pq.empty()) {
            auto x = pq.top();
            pq.pop();
            int u = x.second.first;
            int w = x.second.second;
            int stops = x.first;

            if(stops > k)
                continue;

            for(auto i: adj[u]) {
                int v = i.first;
                int wt = i.second;
                if(distance[v] > w + wt) {
                    distance[v] = w + wt;
                    pq.push({stops+1, {v, distance[v]}});
                }
            }    
        }

        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};