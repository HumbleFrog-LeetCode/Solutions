class Solution {
public:

    void solve(vector<int>& nums, set<vector<int>> &res, int index) {
        if(index >= nums.size()) {
            res.insert(nums);
            return;
        }

        for(int j = index; j < nums.size(); j++) {
            swap(nums[index], nums[j]);
            solve(nums, res, index+1);
            swap(nums[index], nums[j]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        solve(nums, res, 0);
        vector<vector<int>> result;
        for(auto x: res)
            result.push_back(x);
        return result;
    }
};