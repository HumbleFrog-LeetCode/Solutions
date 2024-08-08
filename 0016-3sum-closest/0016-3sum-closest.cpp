class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), i, j, k, sum, diff = INT_MAX, ans;
        for(i = 0; i < n-2; i++) {
            j = i + 1;
            k = n - 1;
            while(j < k) {
                sum = nums[i] + nums[j] + nums[k];
                if(sum == target)
                    return target;
                if(abs(sum - target) < diff) {
                    diff = abs(sum - target);
                    ans = sum;
                }
                if(sum < target)
                    j++;
                if(sum > target)
                    k--;             
            }
        }
        return ans;
    }
};