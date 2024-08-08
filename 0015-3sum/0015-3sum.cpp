class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i, j, k, n = nums.size(), sum;
        set<vector<int>> st;
        
        for(i = 0; i<n-2; i++) {
            j = i + 1;
            k = n-1;
            while(j < k) {
                sum = nums[i] + nums[j] + nums[k];
                if(sum == 0)
                    st.insert({nums[i], nums[j++], nums[k--]});
                else if(sum > 0)
                    k--;
                else
                    j++; 
            }
        }

        vector<vector<int>> res;
        for(auto x: st)
            res.push_back(x);
        return res;   
    }
};