class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count[60] = {0}, ans = 0;
        for(auto t: time) {
            int mod = t % 60;
            if(mod == 0)
                ans += count[0];
            else
                ans += count[60 - mod];
            count[mod]++;    
        }
        return ans;
    }
};