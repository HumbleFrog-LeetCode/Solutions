class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i = 0, j = 0, N = nums.size(), ans = 0, sum = 0, dup = 0;
        unordered_map<int, int> mp;
        for(; j<N; j++) {
            sum += nums[j];
            dup += ++mp[nums[j]] == 2;
            while(i<=j && dup) {
                sum -= nums[i];
                dup -= --mp[nums[i++]] == 1;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};