class Solution {
public:

    int atMost(vector<int>& a, int k) {
        int i = 0, j = 0, N = a.size(), ans = 0, count = 0;
        for(; j<N; j++) {
            count += a[j] & 1;
            while(i<=j && count > k)
                count -= a[i++] & 1;
            ans += j-i;    
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};