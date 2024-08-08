class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int height = log2(label);
        vector<int> ans;
        ans.push_back(label);
        while(height) {
            int left = pow(2, height - 1);
            int right = pow(2, height) - 1;
            label = left + right - label/2;
            ans.push_back(label);
            height--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};