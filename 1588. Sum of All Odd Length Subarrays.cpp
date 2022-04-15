class Solution {
public:
    // Prefix sum solution
    // int sumOddLengthSubarrays(vector<int>& arr) {
    //     int n = arr.size();
    //     int ans = 0;
    //     vector<int> prefix_sum(n + 1, 0);
    //     for(int i = 1; i <= n; i++) {
    //         prefix_sum[i] = prefix_sum[i - 1] + arr[i - 1];
    //     }
    //     for(int i = 0; i < n; i++) {
    //         for(int j = i + 1; j <= n; j += 2) {
    //             ans += prefix_sum[j] - prefix_sum[i];
    //         }
    //     }
    //     return ans;
    // }

    // Mathematical solution
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            int left = i;
            int right = n - i - 1;
            int left_even = left / 2 + 1;
            int left_odd = (left + 1) / 2;
            int right_even = right / 2 + 1;
            int right_odd = (right + 1) / 2;
            ans += (left_even * right_even + left_odd * right_odd) * arr[i];
        }
        return ans;
    }
};