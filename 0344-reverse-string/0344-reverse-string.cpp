class Solution {
public:
    
    void reverse(vector<char>& s, int start, int end) {
        while(start < end)
            swap(s[start++], s[end--]);
    }
    void reverseString(vector<char>& s) {
        reverse(s, 0, s.size()-1);
    }
};