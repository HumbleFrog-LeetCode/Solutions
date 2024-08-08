class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> freq;
        priority_queue<pair<int, int>> pq;
        for(auto x: nums)
            freq[x]++;
        for(auto x: freq)
            pq.push({x.second, x.first});

        for(int i=1; i<=k ; i++) {
            if(!pq.empty()) {
                auto temp = pq.top();
                pq.pop();
                res.push_back(temp.second);
            }
        } 
        return res;   
    }
};