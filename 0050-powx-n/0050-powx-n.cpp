class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        int flag = 0;
        if(n < 0) {
            flag = 1;
            n = abs(n);
        }
        while(n) {
            if(n & 1)
                res *= x;
            x *= x;
            n >>= 1;    
        }
        return flag ? 1/res : res;
    }
};