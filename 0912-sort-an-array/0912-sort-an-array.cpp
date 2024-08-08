class Solution {
public:

    void merge(vector<int>& a, int low, int mid, int high) {
        int m, i, l, k, x, y;
        int temp[50000];
        i = l = low;
        m = mid+1;
        while(l<=mid && m<=high)
            temp[i++] = a[l] <= a[m] ? a[l++] : a[m++];
        l>mid ? (x = m, y = high) : (x = l, y = mid);
        for(k=x; k<=y; k++)
            temp[i++] = a[k];
        for(k=low; k<=high; k++)
            a[k] = temp[k];
    }

    void mergeSort(vector<int>& a, int low, int high) {
        int mid;
        if(low < high) {
            mid = low + (high - low) / 2;
            mergeSort(a, low, mid);
            mergeSort(a, mid+1, high);
            merge(a, low, mid, high);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};