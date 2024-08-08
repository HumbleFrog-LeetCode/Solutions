class Solution {
public:

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        set<vector<int>> st;
        int n = nums.size(), i, j, k, l;
        if(n < 4)
            return res;
        sort(nums.begin(), nums.end());    
        for(i = 0; i< n-3; i++) {
            for(j = i+1; j < n-2; j++) {
                k = j+1, l = n-1;
                while(k < l) {
                    long long sum = (long long) nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum == target) {
                        st.insert({nums[i], nums[j], nums[k], nums[l]});
                        k++, l--;
                    }
                    else if(sum < target)
                        k++;
                    else
                        l--;    
                }
            }
        }

        for(auto x: st)
            res.push_back(x);
        return res;
            
        // while(i < j) {
        //     int sum = pairs[i][0] + pairs[j][0];
        //     if(sum == target) {
        //         if(pairs[i][1] != pairs[j][1] && pairs[i][1] != pairs[j][2] && 
        //            pairs[i][2] != pairs[j][1] && pairs[i][2] != pairs[j][2]) {
        //             vector<int> v;
        //             v.push_back(nums[pairs[i][1]]);
        //             v.push_back(nums[pairs[i][2]]);
        //             v.push_back(nums[pairs[j][1]]);
        //             v.push_back(nums[pairs[j][2]]);
        //             sort(v.begin(), v.end());
        //             st.insert(v);
        //         }
        //         i++, j--;
        //     }
        //     else if(sum < target)
        //         i++;
        //     else 
        //         j--;
        // }
    }
};