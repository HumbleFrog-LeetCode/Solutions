class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> adj;
        for(int i = 0; i < tickets.size(); i++) {
            string u = tickets[i][0];
            string v = tickets[i][1];
            adj[u].insert(v);
        }

        stack<string> s;
        s.push("JFK");
        vector<string> res;
        while(!s.empty()) {
            string src = s.top();
            if(adj[src].empty()) {
                res.push_back(src);
                s.pop();
            }
            else {
                auto x = adj[src].begin();
                s.push(*x);
                adj[src].erase(x);
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
