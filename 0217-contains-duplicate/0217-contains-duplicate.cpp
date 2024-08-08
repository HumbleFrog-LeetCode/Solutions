class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(auto x: nums) {
            if(st.count(x))
                return true;
            st.insert(x);    
        }
        return false;
    }
};