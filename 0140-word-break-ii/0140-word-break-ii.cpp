class Solution {
public:

    void solve(string &s, unordered_set<string> &dict, string output, vector<string> &res, int index) {
        if(index >= s.length()) {
            output.pop_back();
            res.push_back(output);
            return;
        }

        string temp = "";
        for(int i = index; i < s.length(); i++) {
            temp += s[i];
            if(dict.count(temp)) {
                temp += ' ';
                solve(s, dict, output + temp, res, i+1);
                temp.pop_back();
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<string> res;
        solve(s, dict, "", res, 0);
        return res;
    }
};