class Solution {
public:

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

    void reverse(string &s, int start, int end) {
        while(start < end) {
            if(isVowel(s[start]) && isVowel(s[end]))
                swap(s[start++], s[end--]);
            else if(isVowel(s[start]))
                end--;
            else if(isVowel(s[end]))
                start++;
            else
                start++, end--;            
        }
    }

    string reverseVowels(string s) {
        reverse(s, 0, s.size()-1);
        return s;
    }
};