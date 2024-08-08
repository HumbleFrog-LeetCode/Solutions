class Solution {
public:

    typedef pair<int, string> pis;

    struct compare {
        bool operator()(pis a, pis b) {
            if(a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;    
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        unordered_map<string, int> mp;
        for(auto x: words)
            mp[x]++;

        priority_queue<pis, vector<pis>, compare> pq; 
        for(auto x: mp)
            pq.push({x.second, x.first});

        while(!pq.empty() && k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }  

        return res; 
    }
};