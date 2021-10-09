class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int length = nums.size();
        vector<int> dp(length + 1, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2; i <= length; i++){
            if(dp[i - 1] > dp[i - 2] + nums[i - 1]){
                dp[i] = dp[i - 1];
            }else{
                dp[i] = dp[i - 2] + nums[i - 1];
            }
        }
        return dp[length];
    }
};