class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = INT_MIN, sell = 0;
        for(auto price: prices) {
            buy = max(buy, sell - price);
            sell = max(sell, buy + price - fee);
        }
        return sell;
    }
};