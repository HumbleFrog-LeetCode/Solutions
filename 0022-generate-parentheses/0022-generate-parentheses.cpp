class Solution {
public:

    void generate(int start, int end, vector<string> &res, string output) {
        if(start == 0 && end == 0) {
            res.push_back(output);
            output.clear();
        }

        if(start < 0 || end < 0 || start > end)
            return;
        
        output.push_back('(');
        generate(start-1, end, res, output);
        output.pop_back();

        output.push_back(')');
        generate(start, end-1, res, output);
        output.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(n, n, res, "");
        return res;
    }
};