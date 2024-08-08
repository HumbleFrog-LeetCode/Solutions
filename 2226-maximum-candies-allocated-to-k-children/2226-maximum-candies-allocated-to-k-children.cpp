class Solution {
public:

    int possible(vector<int>& a, long long k, long long candies) {
        long long ans = 0;
        for(auto x: a)
            ans += x/candies;
        return ans >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long n = candies.size(), ans = 0;
        long long low = 1, high = *max_element(candies.begin(), candies.end());
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(possible(candies, k, mid)) {
                //ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;    
        }
        //return ans;
        return high;
    }
};