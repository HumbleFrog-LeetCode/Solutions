class Solution {
public:

    int atMost(vector<int> &a, int k) {
        int i = 0, j = 0, N = a.size(), ans = 0, distinct = 0;
        unordered_map<int, int> mp;
        for(; j<N; j++) {
            distinct += ++mp[a[j]] == 1;
            while(i<=j && distinct > k) {
                distinct -= --mp[a[i++]] == 0;
            }
            ans += j-i;
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};