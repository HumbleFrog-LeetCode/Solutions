class Solution {
public:

    int atMost(vector<int>& nums, int goal) {
        int i = 0, j = 0, N = nums.size(), ans = 0, sum = 0;
        for(; j<N; j++) {
            sum += nums[j];
            while(i<=j && sum > goal)
                sum -= nums[i++];
            ans += j-i;   
        }
        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};