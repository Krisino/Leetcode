class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if(sum % 2 == 1 || n == 1) {
            return false;
        }
        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        for(int j = 0; j <= target; j++) {
            if(nums[0] <= j) {
                dp[0][j] = nums[0];
            }
        }
        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= target; j++) {
                if(nums[i] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
                }
            }
        }
        return dp[n - 1][target] == target;
    }
};