class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i = 0, j = 0, N = s.size(), ans = 0, cost = 0;
        for(; j<N; j++) {
            cost += abs(s[j] - t[j]);
            while(i<=j && cost > maxCost)
                cost -= abs(s[i] - t[i++]);
            ans = max(ans, j-i+1);    
        }
        return ans;
    }
};
