class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());

        while(low <= high) {
            int mid = low + (high - low) / 2;
            int taken = 0;
            for(int i = 0; i < nums.size(); i++)
                if(mid >= nums[i])
                    taken++, i++;
            if(taken < k)
                low = mid + 1;
            else
                high = mid - 1;            
        }        
        return low;
    }
};