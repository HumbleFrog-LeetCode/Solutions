class Solution {
public:

    bool solve(string &s1, string &s2, string &s3, int i, int j, vector<vector<int>> &dp) {
        if(i + j == s3.size())
            return true;

        if(dp[i][j] != -1)
            return dp[i][j];

        bool ans = 0; 

        if(i < s1.size() && s1[i] == s3[i+j])
            ans |= solve(s1, s2, s3, i+1, j, dp);
            
        if(j < s2.size() && s2[j] == s3[i+j])
            ans |= solve(s1, s2, s3, i, j+1, dp);
            
        return dp[i][j] = ans;    
    }

    bool isInterleave(string s1, string s2, string s3) {
        int i = s1.length(), j = s2.length(), k = s3.length();
        if((i + j) != k)
            return false;
        vector<vector<int>> dp(i+1, vector<int>(j+1, -1));
        return solve(s1, s2, s3, 0, 0, dp);
    }
};