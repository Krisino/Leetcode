class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for(int i = 2; i <= n; i++) {
            // i 代表目前所求数
            for(int j = 2; j < i; j++) {
                // j 代表进行拆分的大小，拆分 1 无意义，故 j 从 2 开始
                dp[i] = max(dp[i], max(dp[j], j) * (i - j));
            }
        }
        return dp[n];
    }
};