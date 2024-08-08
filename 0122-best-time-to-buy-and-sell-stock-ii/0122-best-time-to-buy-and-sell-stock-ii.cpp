class Solution {
public:

    int solve(vector<int> &prices, int index, int buy, vector<vector<int>> &dp) {
        if(index >= prices.size())
            return 0;

        if(dp[index][buy] != -1)
            return dp[index][buy];

        int profit = 0;
        if(buy) {
            int buyStock = -prices[index] + solve(prices, index+1, 0, dp);
            int skipStock = solve(prices, index+1, 1, dp);
            profit = max(buyStock, skipStock);
        }
        else {
            int sellStock = prices[index] + solve(prices, index+1, 1, dp);
            int skipStock = solve(prices, index+1, 0, dp);
            profit = max(sellStock, skipStock);
        }
        return dp[index][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return solve(prices, 0, 1, dp);
    }
};