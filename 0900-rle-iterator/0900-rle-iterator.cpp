class RLEIterator {
    vector<int> a;
    int i = 0;
public:
    RLEIterator(vector<int>& encoding) {
        a = encoding;
        i = 0;
    }
    
    int next(int n) {
        if(i == a.size())
            return -1;
        if(n <= a[i]) {
            a[i] -= n;
            return a[i+1];
        }
        n -= a[i];
        i += 2;
        return next(n);    
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */


