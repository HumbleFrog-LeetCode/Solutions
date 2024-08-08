class MinStack {
    stack<long> s;
    long mini = LONG_MAX;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(s.empty()) {
            s.push((long) val);
            mini = (long) val;
        }
        else {
            if((long)val < mini) {
                long x = (long)(2 * long(val) - mini);
                s.push(x);
                mini = (long)val;
            }
            else 
                s.push(val); 
        }    
    }
    
    void pop() {
        if(s.empty())
            return;

        long top = s.top();
        s.pop();

        if(top < mini) {
            long prevMin = mini;
            long val = 2 * mini - top;
            mini = val;
        }
    }
    
    int top() {
        long top = s.top();
        if(top > mini)
            return (int)top;
        else
            return (int)mini;  
    }
    
    int getMin() {
        return (int)mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */