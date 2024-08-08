class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++) {
            if(res.back()[1] > intervals[i][0])
                res.back()[1] = min(res.back()[1], intervals[i][1]); // Take MIN instead of MAX
            else
                res.push_back(intervals[i]);    
        }
        return intervals.size() - res.size();
    }
};