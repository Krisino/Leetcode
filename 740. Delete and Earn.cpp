class Solution {
public:
    // int deleteAndEarn(vector<int>& nums) {
    //     if(nums.size() == 0) {
    //         return 0;
    //     } else if(nums.size() == 1) {
    //         return nums[0];
    //     }
    //     int n = nums.size();
    //     int maxNum = 0;
    //     for(int num: nums){
    //         if(num > maxNum){
    //             maxNum = num;
    //         }
    //     }
    //     vector<int> dp(maxNum + 1),all(maxNum + 1);
    //     for(int num: nums) {
    //         all[num]++;
    //     }
    //     dp[0] = 0;
    //     dp[1] = all[1];
    //     for(int i = 2; i <= maxNum; i++) {
    //         dp[i] = max(dp[i - 1], dp[i - 2] + i*all[i]);
    //     }
    //     return dp[maxNum];
    // }

        int deleteAndEarn(vector<int>& nums) {
        vector<int> arr(100001);
        int maxValue = 0;
        for(int i = 0; i < nums.size(); i++) {
            arr[nums[i]]++;
            maxValue = max(maxValue, nums[i]);
        }
        vector<vector<int> > dp(maxValue + 1, vector<int>(2, 0));
        for(int i = 1; i <= maxValue; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + i * arr[i];
        }
        return max(dp[maxValue][0], dp[maxValue][1]);
    }
};