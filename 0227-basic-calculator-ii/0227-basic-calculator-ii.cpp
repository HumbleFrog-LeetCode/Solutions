class Solution {
public:
    int calculate(string s) {
        long long int sum = 0;
        char sign = '+';
        stack<int> st;
        for(long long int i = 0; i < s.length(); i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                long long int num = 0;
                while(i<s.length() && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + s[i] - '0';
                    i++;
                }   
                i--; 
                if(sign == '+')
                    st.push(num);
                else if(sign == '-')
                    st.push(-num);
                else if(sign == '*') {
                    int x = st.top();
                    st.pop();
                    st.push(x * num);
                }           
                else if(sign == '/') {
                    int x = st.top();
                    st.pop();
                    st.push(x / num);
                } 
            }
            else if(s[i] != ' ')
                sign = s[i];   
        }

        while(!st.empty()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};