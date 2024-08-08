class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), i = 0, ans = INT_MIN;
        stack<int> s;
        while(i < n) {
            if(s.empty() || heights[i] >= heights[s.top()])
                s.push(i++);
            else {
                int tp = s.top();
                s.pop();
                int max_area = heights[tp] * (s.empty() ? i : i - s.top() - 1);
                ans = max(ans, max_area);
            }    
        }

        while(!s.empty()) {
            int tp = s.top();
            s.pop();
            int max_area = heights[tp] * (s.empty() ? i : i - s.top() - 1);
            ans = max(ans, max_area);
        }
        return ans;
    }
};