class Solution {
public:

    int solveTab1(string &a, string &b, int m, int n) {
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

    int solveTab(string &a, string &b, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(a[i-1] == b[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);    
            }
        }
        return dp[m][n];
    }

    int solve(string &a, string &b, int i, int j, vector<vector<int>> &dp) {
        if(i < 0 || j < 0)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(a[i] == b[j])
            return dp[i][j] = 1 + solve(a, b, i-1, j-1, dp);
        else
            return dp[i][j] = max(solve(a, b, i-1, j, dp), solve(a, b, i, j-1, dp));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int i = text1.length();
        int j = text2.length();
        //vector<vector<int>> dp(i+1, vector<int>(j+1, -1));
        //return solve(text1, text2, i-1, j-1, dp);
        //return solveTab(text1, text2, i, j);
        return solveTab1(text1, text2, i, j);
    }
};