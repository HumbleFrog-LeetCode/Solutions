class Solution {
public:

    int solveTab(string &a, string &b, int m, int n) {
        vector<int> curr(n+1, 0);
        vector<int> prev(n+1, 0);
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(a[i-1] == b[j-1])
                    curr[j] = 1 + prev[j-1];
                else
                    curr[j] = max(prev[j], curr[j-1]);    
            }
            prev = curr;
        }
        return prev[n];
    }

    int longestPalindromeSubseq(string s) {
        int m = s.length();
        string s1 = s;
        reverse(s.begin(), s.end());
        return solveTab(s, s1, m, m);
    }
};