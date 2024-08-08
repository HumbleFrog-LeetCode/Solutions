class CombinationIterator {
    vector<string> res;
    int length = 0;
    
public:
    CombinationIterator(string characters, int combinationLength) {
        helper(characters, 0, combinationLength, "");
    }

    void helper(string &s, int index, int maxLength, string output) {
        if(output.length() == maxLength) {
            res.push_back(output);
            return;
        }
        for(int j = index; j < s.length(); j++) {
            output.push_back(s[j]);
            helper(s, j+1, maxLength, output);
            output.pop_back();
        }
    }
    
    string next() {
        return res[length++];
    }
    
    bool hasNext() {
        return length < res.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */