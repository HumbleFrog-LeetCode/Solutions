class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, N = s.size(), ans = 0, count[128] = {0}, dup = 0;
        for(; j<N ; j++) {
            dup += ++count[s[j]] == 2;
            while(i<=j && dup) 
                dup -= --count[s[i++]] == 1;
            ans = max(ans, j-i+1);
        }
        return ans;
        
    }
};