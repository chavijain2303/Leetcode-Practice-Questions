class Solution {
public:
    void reverse(vector<int>& arr, int start, int end) {
        while(start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;

            start++;
            end--;
        }
    }  
    
    void rotate(vector<int>& arr, int k) {
        int n = arr.size();
        k = k % n;

        reverse(arr, 0, n - k - 1); 
        reverse(arr, n - k, n - 1);
        reverse(arr, 0, n - 1);
    }
};
