class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0, j = 0, N = nums.size(), ans = 0, count = 0;
        for(; j<N; j++) {
            count += nums[j] == 0;
            while(i<=j && count > 1)
                count -= nums[i++] == 0;
            ans = max(ans, j-i);    
        }
        return ans;
    }
};