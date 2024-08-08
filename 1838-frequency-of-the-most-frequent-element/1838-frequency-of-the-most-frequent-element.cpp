class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        unsigned int i = 0, j = 0, N = nums.size(), sum = 0, ans = 0;
        sort(nums.begin(), nums.end());
        for(; j<N; j++) {
            sum += nums[j];
            while(i<=j && ((j-i+1) * nums[j]) - sum > k)
                sum -= nums[i++];
            ans = max(ans, j-i+1);    
        }
        return ans;
    }
};