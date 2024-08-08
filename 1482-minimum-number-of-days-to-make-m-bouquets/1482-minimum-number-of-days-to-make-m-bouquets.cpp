class Solution {
public:

    bool possible(vector<int> &a, int m, int k, int mid) {
        int sum = 0, count = 0;
        for(auto x: a) {
            if(x <= mid)
                sum++;
            else {
                count += sum/k;
                sum = 0;
            }   
        }
        count += sum/k;
        return count >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 1, high = *max_element(bloomDay.begin(), bloomDay.end());
        int n = bloomDay.size();
        if(m > n || k > n || m * k > n)
            return -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(possible(bloomDay, m, k, mid))
                high = mid - 1;
            else
                low = mid + 1;       
        }    
        return low;
        
    }
};