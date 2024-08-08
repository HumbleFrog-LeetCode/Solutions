class Solution {
public:
    bool isAnagram(string s, string t) {

        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return s == t;
        
        int count[26] = {};
        for(auto c: s)
            count[c - 'a']++;
        for(auto c: t)
            count[c - 'a']--;   
        for(int i = 0; i < 26; i++)
            if(count[i])
                return false;
        return true;
    }
};