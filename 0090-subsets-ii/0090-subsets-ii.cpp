class Solution {
public:

    void solve(vector<int> &nums, set<vector<int>> &s, vector<int> ans, int index) {
        if(index >= nums.size()) {
            s.insert(ans);
            return;
        }

        solve(nums, s, ans, index+1);
        ans.push_back(nums[index]);
        solve(nums, s, ans, index+1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<int> ans;
        solve(nums, s, ans, 0);
        vector<vector<int>> res;
        for(auto x: s)
            res.push_back(x);
        return res;    
    }
};