class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0, j = 0, N = nums.size(), ans = 0, prod = 1;
        for(; j<N; j++) {
            prod *= nums[j];
            while(i<=j && prod >=k)
                prod /= nums[i++];
            ans += j-i+1;    
        }
        return ans;
    }
};