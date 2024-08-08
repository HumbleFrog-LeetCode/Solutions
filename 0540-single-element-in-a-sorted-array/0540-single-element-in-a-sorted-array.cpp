class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        while(low <= high) {
            if(low == high)
                return nums[low];
            if(high == low + 1)
                return -1;    
            int mid = low + (high - low) / 2;
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
                return nums[mid];
            if(nums[mid] == nums[mid-1]) {
                if((high - mid) & 1)
                    low = mid + 1;
                else
                    high = mid - 2;    
            }
            if(nums[mid] == nums[mid+1]) {
                if((mid - low) & 1)
                    high = mid - 1;
                else
                    low = mid + 2;
            }
        }
        return -1;
    }
};