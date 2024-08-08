class Solution {
public:

    long long totalHours(vector<int> &a, int k) {
        long long totalHours = 0;
        for(auto x: a)
            totalHours += x % k ? x/k + 1 : x/k;
        return totalHours;    
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = INT_MIN;
        for(auto x: piles)
            maxi = max(maxi, x);
        int low = 1, high = maxi;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(totalHours(piles, mid) <= h)
                high = mid - 1;
            else 
                low = mid + 1;
        }    
        return low;
    }
};