class Solution {
public:

    int solve(vector<int> &prices, int index, int buy, int k, vector<vector<vector<int>>> &dp) {
        if(index >= prices.size() || k == 0)
            return 0;

        if(dp[index][buy][k] != -1)
            return dp[index][buy][k];

        int profit = 0;
        if(buy) {
            int buyStock = -prices[index] + solve(prices, index+1, 0, k, dp);
            int skipStock = solve(prices, index+1, 1, k, dp);
            profit = max(buyStock, skipStock);
        }
        else {
            int sellStock = prices[index] + solve(prices, index+1, 1, k-1, dp);
            int skipStock = solve(prices, index+1, 0, k, dp);
            profit = max(sellStock, skipStock);
        }
        return dp[index][buy][k] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 2; // Atmost 2 transactions
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return solve(prices, 0, 1, k, dp);
        
    }
};