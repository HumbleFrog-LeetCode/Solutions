class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low = 0, high = arr.size() - k;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(x - arr[mid] > arr[mid + k] - x)
                low = mid + 1;
            else 
                high = mid;    
        }

        vector<int> res;
        for(int i = low; i < low + k; i++)
            res.push_back(arr[i]);
        return res;
    }
};


