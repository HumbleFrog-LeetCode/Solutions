class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target)
            return 0;
        
        unordered_map<int, list<int>> adj; // stop, {list of routes}
        for(int i = 0; i < routes.size(); i++) {
            for(auto stop: routes[i])
                adj[stop].push_back(i);
        }    

        queue<int> q;
        unordered_set<int> visited;
        for(auto i: adj[source]) {
            q.push(i);
            visited.insert(i);
        }

        int buses = 0;
        while(!q.empty()) {
            buses++;
            int size = q.size();
            while(size--) {
                int route = q.front();
                q.pop();
                for(auto stop: routes[route]) {
                    if(stop == target)
                        return buses;
                    for(auto nextRoute: adj[stop]) {
                        if(!visited.count(nextRoute)) {
                            visited.insert(nextRoute);
                            q.push(nextRoute);
                        }
                    }
                }
            }
        }
        return -1; 
    }
};