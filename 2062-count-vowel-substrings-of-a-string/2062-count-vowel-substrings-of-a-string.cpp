class Solution {
public:

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int atMost(string s, int k) {
        int i = 0, j = 0, N = s.size(), ans = 0;
        unordered_map<char, int> mp;
        for(; j<N; j++) {
            if(!isVowel(s[j])) {
                i = j + 1;
                mp.clear();
                continue;
            }
            mp[s[j]]++;
            while(i<=j && mp.size() > k) {
                if(--mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;  
            }
            ans += j-i+1;   
        }
        return ans;
    }

    int countVowelSubstrings(string word) {
        return atMost(word, 5) - atMost(word, 4);
    }
};