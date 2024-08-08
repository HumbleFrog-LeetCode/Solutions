class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high) {
            int mid = low + ((high - low)>>1);
            if(nums[mid] == target)
                return true;
            if(nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++, high--;
                continue;
            }
                
            if(nums[low] <= nums[mid]) {
                if(target >= nums[low] && target <= nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;    
            }
            else {
                if(target >= nums[mid] && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;    
            }    
        }
        return false;
    }
};