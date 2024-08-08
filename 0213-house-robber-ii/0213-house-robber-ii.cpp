class Solution {
public:

    int robUtil(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];

        int ans = 0;
        int prev2 = 0;
        int prev1 = nums[0];
        for(int i = 1; i < n; i++) {
            ans = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;      
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        vector<int> firstHouseExcluded(nums.begin()+1, nums.end());
        vector<int> lastHouseExcluded(nums.begin(), nums.end()-1);
        return max(robUtil(firstHouseExcluded), robUtil(lastHouseExcluded));
    }
};