class Solution {
public:

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b) {
            if(a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });
        
        vector<int> temp;
        temp.push_back(envelopes[0][1]);
        for(int i = 1; i < envelopes.size(); i++) {
            if(envelopes[i][1] > temp.back())
                temp.push_back(envelopes[i][1]);
            else {
                int index = lower_bound(temp.begin(), temp.end(), envelopes[i][1]) - temp.begin();
                temp[index] = envelopes[i][1];
            }    
        }
        return temp.size();
    }
};