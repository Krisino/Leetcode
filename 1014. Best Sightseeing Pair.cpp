class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxScore = 0;
        int n = values.size();
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = values[0];
        for(int i = 1; i < n; i++) {
            dp[i] = max(dp[i-1], values[i - 1] + i - 1);
            maxScore = max(maxScore, dp[i] + values[i] - i);
        }
        return maxScore;
    }
};