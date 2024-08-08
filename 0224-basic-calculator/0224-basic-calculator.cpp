class Solution {
public:
    int calculate(string s) {
        long long int sum = 0, sign = 1;
        stack<int> st;
        for(long long int i = 0; i < s.length(); i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                long long int num = 0;
                while(i<s.length() && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                sum += sign * num;    
                i--;    
            }
            else if(s[i] == '+')
                sign = 1;
            else if(s[i] == '-')
                sign = -1;
            else if(s[i] == '(') {
                st.push(sum);
                st.push(sign);
                sum = 0;
                sign = 1;
            }
            else if(s[i] == ')') {
                sum = st.top() * sum;
                st.pop();
                sum += st.top();
                st.pop();
            }        
        }
        return sum;
    }
};