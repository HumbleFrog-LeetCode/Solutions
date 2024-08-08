class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> res(n, 0);
        priority_queue<int, vector<int>, greater<int>> available; // room
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy; // {endTime, room}

        for(int i = 0; i < n; i++)
            available.push(i);

        sort(meetings.begin(), meetings.end());
        for(auto x: meetings) {
            long long start = x[0], end = x[1];

            while(!busy.empty() && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }

            if(!available.empty()) {
                int room = available.top();
                res[room]++;
                available.pop();
                busy.push({end, room});
            }
            else {
                long long end1 = busy.top().first;
                int room = busy.top().second;
                busy.pop();
                res[room]++;
                busy.push({end1 + end - start, room});
            }
        } 
        return max_element(res.begin(), res.end()) - res.begin();   
    }
};

