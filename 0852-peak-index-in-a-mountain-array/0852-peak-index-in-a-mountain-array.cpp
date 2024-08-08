class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int low = 0, high = n-1;
        while(low <= high) {
            if(low == high)
                return low;
            if(high == low + 1)
                return arr[low] > arr[high] ? low : high;
            int mid = low + (high - low) / 2;
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
                return mid;
            if(arr[mid] > arr[mid-1])
                low = mid + 1;
            else 
                high = mid - 1;        
        }
        return -1; 
    }
};