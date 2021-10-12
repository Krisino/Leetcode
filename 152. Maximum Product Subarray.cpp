class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) {
            return 0;
        } else if (n == 1) {
            return nums[0];
        }
        int dp = nums[0];
        int maxDp = nums[0];
        int minDp = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            int maxDpCopy = maxDp;
            maxDp = max(max(maxDp * nums[i], nums[i]), minDp * nums[i]);
            minDp = min(min(maxDpCopy * nums[i], nums[i]), minDp * nums[i]);
            dp = max(dp, maxDp);
        }
        return dp;
    }
};