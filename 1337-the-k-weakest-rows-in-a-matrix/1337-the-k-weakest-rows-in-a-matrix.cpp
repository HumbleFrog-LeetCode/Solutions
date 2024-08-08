class Solution {
public:

    struct compare {
        bool operator()(pair<int, int> a, pair<int, int> b) {
            if(a.first == b.first)
                return a.second > b.second;
            return a.first > b.first;    
        }
    };

    int lowerBound(vector<int> &a, int n) {
        int low = 0, high = n-1;
        int ans = n;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(a[mid] == 0) {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans-n;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        int n = mat[0].size();
        int row = 0;
        for(auto x: mat) {
            int index = lowerBound(x, n);
            pq.push({index, row++});
        }

        vector<int> res;
        while(k-- && !pq.empty()) {
            auto x = pq.top();
            pq.pop();
            res.push_back(x.second);
        }
        return res;
    }
};