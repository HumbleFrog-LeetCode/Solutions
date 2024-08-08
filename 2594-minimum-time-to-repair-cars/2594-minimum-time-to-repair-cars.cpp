class Solution {
public:

    bool repairPossible(vector<int>& a, int cars, long long minTime) {
        long long carsRepaired = 0;
        for(auto x: a)
            carsRepaired += sqrt(minTime / x);
        return carsRepaired >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long mini = *min_element(ranks.begin(), ranks.end());
        long long low = 1, high = mini * cars * cars;
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(repairPossible(ranks, cars, mid))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};