class Solution {
public:
    int minOperations(vector<int>& nums) {
        int i = 0, j = 0, N = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int M = nums.size();
        for(; j<M; j++) {
            while(i<=j && nums[i] + N <= nums[j])
                i++;
            ans = max(ans, j-i+1);
        }
        return N - ans;
    }
};