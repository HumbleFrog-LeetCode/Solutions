class Solution {
public:

    bool shippingPossible(vector<int> &a, int days, int capacity) {
        int totalDays = 1;
        int sum = 0;
        for(auto x: a) {
            sum += x;
            if(sum > capacity) {
                totalDays++;
                sum = x;
            }
            
        }
        return totalDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = weights[0], high = 0; 
        
        for(auto x: weights) {
            low = max(low, x);
            high += x;
        }
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(shippingPossible(weights, days, mid))
                high = mid - 1;
            else
                low = mid + 1;    
        }
        return low;
    }
};