class Solution {
    public int rob(int[] nums) {
        int[] dp = new int[2];
        dp[0] = nums[0];
        if(nums.length == 1) {
            return dp[0];
        }
        dp[1] = Math.max(nums[0], nums[1]);
        for(int i = 2; i < nums.length; i++) {
            int temp = dp[1];
            dp[1] = Math.max(dp[1], dp[0] + nums[i]);
            dp[0] = temp;
        }
        return dp[1];
    }
}