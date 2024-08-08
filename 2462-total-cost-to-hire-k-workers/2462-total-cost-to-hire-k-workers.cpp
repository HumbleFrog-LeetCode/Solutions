class Solution {
public:

    struct compare {
        bool operator()(pair<int, int> a, pair<int, int> b) {
            if(a.first == b.first)
                return a.second > b.second;
            return a.first > b.first;
        }
    };

    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long cost = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        int n = costs.size();
        if(n == 1) return costs[0];
        int i, j;
        for(i=0, j=n-1; i<candidates && i<j; i++, j--) {
                pq.push({costs[i], i});
                pq.push({costs[j], j});
        }
        while(k--) {
            auto temp = pq.top();
            pq.pop();
            cost += temp.first;
            if(i<=j) {
                if(temp.second > j) {
                    pq.push({costs[j], j});
                    j--;
                }
                else {
                    pq.push({costs[i], i});
                    i++;
                }
            }
        }

        return cost;
    }
};