class Solution {
public:

    void solve(string digits, string mapping[], vector<string> &res, string output, int index) {
        if(index >= digits.size()) {
            res.push_back(output);
            return;
        }

        string word = mapping[digits[index] - '0'];
        for(int j = 0; j < word.size(); j++) {
            output.push_back(word[j]);
            solve(digits, mapping, res, output, index+1);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size() == 0)
            return res;
        string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, mapping, res, "", 0);
        return res;
    }
};