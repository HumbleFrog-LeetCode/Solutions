class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq; // score, id
        int n = score.size();
        for(int i = 0; i < n; i++)
            pq.push({score[i], i});

        int rank = 1;
        vector<string> res(n);
        while(!pq.empty()) {
            auto x = pq.top();
            pq.pop();
            if(rank == 1)
                res[x.second] = "Gold Medal";
            else if(rank == 2)
                res[x.second] = "Silver Medal";   
            else if(rank == 3)
                res[x.second] = "Bronze Medal";  
            else
                res[x.second] = to_string(rank);  
            rank++;
        }    
        return res;
    }
};