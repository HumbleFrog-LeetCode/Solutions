class Solution {
public:
    string intToRoman(int num) {
        int numbers[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string res = "";
        int i = 0;
        while(num) {
            if(num >= numbers[i]) {
                res += romans[i];
                num -= numbers[i];
            }
            else
                i++;
        }
        return res;
    }
};