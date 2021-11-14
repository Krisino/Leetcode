class Solution {
public:
    // Version 1: common dp array with the size of n+1
    // int minCostClimbingStairs(vector<int>& cost) {
    //     vector<int> dp(cost.size()+1);
    //     dp[0] = 0;
    //     dp[1] = 0;
    //     for(int i = 2; i <= cost.size(); i++) {
    //         dp[i] = min(dp[i - 2] + cost[i - 2],dp[i - 1] + cost[i - 1]);
    //     }
    //     return dp[cost.size()];
    // }
    // Version 2: Optimized by using three variables
    int minCostClimbingStairs(vector<int>& cost) {
        int preCost = 0;
        int curCost = 0;
        int minCost = 0;
        for(int i = 2; i <= cost.size(); i++) {
            minCost = min(preCost + cost[i - 2], curCost + cost[i -1]);
            preCost = curCost;
            curCost = minCost;
        }
        return minCost;
    }
};