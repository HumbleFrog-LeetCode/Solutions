class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char, int> mp1, mp2;
        vector<int> ans;
        for(auto x: p)
            mp1[x]++;
        int n = s.size(), m = p.size();  
        int i = 0, j = 0;
        while(j < n) {
            mp2[s[j]]++;
            if(j - i + 1 == m) {
                if(mp1 == mp2)
                    ans.push_back(i);
                mp2[s[i]]--;
                if(mp2[s[i]] == 0)
                    mp2.erase(s[i]);
                i++;        
            }
            j++;
        }  
        return ans;
    }
};
