class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> s;
        for(int i = nums2.size()-1 ; i >=0 ; i--) {
            while(!s.empty() && s.top() <= nums2[i])
                s.pop();
            mp[nums2[i]] = s.empty() ? -1 : s.top();
            s.push((nums2[i]));
        }

        for(int i = 0; i < nums1.size(); i++) 
            nums1[i] = mp[nums1[i]];
        return nums1;
    }
};