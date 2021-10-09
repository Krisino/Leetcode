class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        } else if(nums.size() == 1) {
            return nums[0];
        }
        int n = nums.size();
        int maxNum = 0;
        for(int num: nums){
            if(num > maxNum){
                maxNum = num;
            }
        }
        vector<int> dp(maxNum + 1),all(maxNum + 1);
        for(int num: nums) {
            all[num]++;
        }
        dp[0] = 0;
        dp[1] = all[1];
        for(int i = 2; i <= maxNum; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + i*all[i]);
        }
        return dp[maxNum];
    }
};