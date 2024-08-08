class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0, N = nums.size(), ans = 0, count = 0;
        for(; j<N; j++) {
            count += nums[j] == 1;
            while(i<=j && j - i + 1 - count > k)
                count -= nums[i++] == 1;
            ans = max(ans, j-i+1);    
        }
        return ans;
    }
};