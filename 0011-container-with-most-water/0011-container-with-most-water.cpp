class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1, ans = INT_MIN;
        while(l < r) {
            ans = max(ans, (r - l) * min(height[l], height[r]));
            height[l] < height[r] ? l++ : r--;
        }
        return ans;
    }
};