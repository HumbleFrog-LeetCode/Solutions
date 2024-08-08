class Solution {
public:

    int first(vector<int> &a, int target, int n) {
        int low = 0, high = n-1;
        int res = n;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(a[mid] >= target) {
                res = mid;
                high = mid - 1;
            }
            else
               low = mid + 1;
        }
        return res;
    }

    int last(vector<int> &a, int target, int n) {
        int low = 0, high = n-1;
        int res = n;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(a[mid] > target) {
                res = mid;
                high = mid - 1;
            }
            else
               low = mid + 1;
        }
        return res;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = first(nums, target, n);
        if(lb == n || nums[lb] != target)
            return {-1, -1};
        int ub = last(nums, target, n);
        return {lb, ub-1};
    }
};