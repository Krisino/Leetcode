class Solution {
public:
// Version 1
    // bool canJump(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> dp(n);
    //     dp[0] = nums[0];
    //     for(int i = 1; i < n; i++) {
    //         if(dp[i - 1] == 0) {
    //             return false;
    //         }
    //         dp[i] = max(nums[i],dp[i - 1] - 1);
    //     }
    //     return true;
    // }
// Version 2 
        bool canJump(vector<int>& nums) {
        int n = nums.size();
        int step = nums[0],maxStep;//step = dp[i - 1], maxStep = dp[i]
        for(int i = 1; i < n; i++) {
            if(step == 0) {
                return false;
            }
            maxStep = max(step - 1, nums[i]);
            step = maxStep;
        }
        return true;
    }
};