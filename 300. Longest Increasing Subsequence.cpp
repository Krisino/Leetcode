class Solution {
public:
    // dp
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     int result = 1;
    //     vector<int> dp(n, 1);
    //     for(int i = 1; i < n; i++) {
    //         for(int j = 0; j < i; j++) {
    //             if(nums[i] > nums[j]) {
    //                 dp[i] = max(dp[i], dp[j] + 1);
    //                 if(dp[i] > result) {
    //                     result = dp[i];
    //                 }
    //             }
    //         }
    //     }
    //     return result;
    // }

    // dp + binarySearch
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) {
            return n;
        }
        vector<int> tail;
        tail.push_back(nums[0]);
        int end_idx = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i] > tail[end_idx]) {
                tail.push_back(nums[i]);
                end_idx++;
            } else {
                int l = 0;
                int r = end_idx;
                while(l < r) {
                    int mid = l + (r - l) / 2;
                    if(tail[mid] < nums[i]) {
                        l = mid + 1;
                    } else {
                        r = mid;
                    }
                }
                tail[l] = nums[i];
            }
        }
        return end_idx + 1;
    }
};