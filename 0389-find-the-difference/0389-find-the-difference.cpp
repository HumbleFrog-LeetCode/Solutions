class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        int i;
        for(i = 0; i < s.size(); i++) {
            if(s[i] != t[i])
                return t[i];
        }
        return t[i];
    }
};