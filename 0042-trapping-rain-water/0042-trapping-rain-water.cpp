class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1, leftMax = INT_MIN, rightMax = INT_MIN, ans = 0;
        while(l < r) {
            leftMax = max(leftMax, height[l]);
            rightMax = max(rightMax, height[r]);
            ans += leftMax < rightMax ? leftMax - height[l++] : rightMax - height[r--];
        }
        return ans;
    }
};
