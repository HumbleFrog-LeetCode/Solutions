class Solution {
public:

    struct compare {
        bool operator()(vector<int> &a, vector<int> &b) {
            return a[0] * a[0] + a[1] * a[1] > b[0] * b[0] + b[1] * b[1];
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;
        for(auto x: points)
            pq.push(x);

        vector<vector<int>> res;
        while(!pq.empty() && k--) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;    
    }
};