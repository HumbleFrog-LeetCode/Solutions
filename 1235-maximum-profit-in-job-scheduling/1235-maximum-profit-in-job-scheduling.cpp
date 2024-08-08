class Solution {
public:

    int solve(int index, vector<vector<int>> &jobs, vector<int> &startTime, vector<int> &dp) {
        if(index >= jobs.size())
            return 0;

        if(dp[index] != -1)
            return dp[index];

        int nextIndex = lower_bound(startTime.begin(), startTime.end(), jobs[index][1]) - startTime.begin();
        int include = jobs[index][2] + solve(nextIndex, jobs, startTime, dp);
        int exclude = solve(index+1, jobs, startTime, dp);
        return dp[index] = max(include, exclude);    
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        int n = startTime.size();
        for(int i = 0; i < n; i++) 
            jobs.push_back({startTime[i], endTime[i], profit[i]});

        sort(jobs.begin(), jobs.end());    
        sort(startTime.begin(), startTime.end());

        vector<int> dp(n, -1);
        return solve(0, jobs, startTime, dp);
    }
};