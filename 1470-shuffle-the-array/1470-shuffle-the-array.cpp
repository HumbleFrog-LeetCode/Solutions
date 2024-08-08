class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        for(int i = 0; i < nums.size(); i++) {
            int currNum = nums[i];
            int currPos = i;
            while(currNum > 0) {
                int newPos = 0;
                if(currPos < n)
                    newPos = 2 * currPos;
                else
                    newPos = 2 * (currPos - n) + 1;
                int newNum = nums[newPos];
                nums[newPos] = -currNum;
                currNum = newNum;
                currPos = newPos;
            }
        }
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] < 0)
                nums[i] = -nums[i];
        return nums;
    }
};


