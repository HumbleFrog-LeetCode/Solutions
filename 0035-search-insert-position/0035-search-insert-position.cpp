class Solution {
public:

    int lowerBound(vector<int> &a, int target, int n) {
        int low = 0, high = n-1;
        int ans = n;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(a[mid] >= target) {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }

    int searchInsert(vector<int>& nums, int target) {
        return lowerBound(nums, target, nums.size());
        
    }
};