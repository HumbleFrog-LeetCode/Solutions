class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        unsigned int num = x, rev = 0, rem = 0;
        while(num) {
            rem = num % 10;
            rev = rev * 10 + rem;
            num = num / 10;
        }
        return rev == x ? true : false;
    }
};