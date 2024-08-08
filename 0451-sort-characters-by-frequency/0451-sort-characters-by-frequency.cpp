class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(auto c: s)
            mp[c]++;

        priority_queue<pair<int, char>> pq;
        for(auto x: mp)
            pq.push({x.second, x.first});

        string res = "";
        while(!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            for(int i = 1; i<= temp.first; i++)
                res += temp.second;
        }  
        return res;  
    }
};