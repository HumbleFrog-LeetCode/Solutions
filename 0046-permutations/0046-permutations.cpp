class Solution {
public:

    void solve(vector<int>& nums, vector<vector<int>> &res, int index) {
        if(index >= nums.size()) {
            res.push_back(nums);
            return;
        }

        for(int j = index; j < nums.size(); j++) {
            swap(nums[index], nums[j]);
            solve(nums, res, index+1);
            swap(nums[index], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        solve(nums, res, 0);
        return res;
    }
};