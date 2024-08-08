class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0, N = s.size(), ans = 0, count[26] = {0};
        for(; j<N; j++) {
            count[s[j] - 'A']++;
            while(i<=j && j - i + 1 - *max_element(count, count+26) > k)
                count[s[i++] - 'A']--;
            ans = max(ans, j-i+1);    
        }
        return ans;
    }
};