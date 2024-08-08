class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        visited[0] = true;
        stack<int> s;
        s.push(0);
        while(!s.empty()) {
            auto x = s.top();
            s.pop();
            for(auto i: rooms[x]) {
                if(!visited[i]) {
                    visited[i] = true;
                    s.push(i);
                }
            }
        }

        for(auto x: visited)
            if(!x)
                return false;
        return true;        
    }
};