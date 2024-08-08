class Solution {
public:

    void solve(vector<int>& nums, set<vector<int>> &res, vector<int> ans, int index) {
        if(index >= nums.size()) {
            res.insert(ans);
            return;
        }

        solve(nums, res, ans, index+1);
        ans.push_back(nums[index]);
        solve(nums, res, ans, index+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> ans;
        solve(nums, res, ans, 0);
        vector<vector<int>> result;
        for(auto x: res)
            result.push_back(x);
        return result;    
    }
};