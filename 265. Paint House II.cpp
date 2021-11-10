class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        if(n == 0) {
            return 0;
        }
        int k = costs[0].size();
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < k; j++) {
                int temp = 2147483647;
                for(int p = 0; p < k; p++){
                    if(p == j) {
                        continue;
                    }
                    temp = min(temp, costs[i-1][p]);
                }
                costs[i][j] += temp;
            }
        }
        int ans = costs[n-1][0];
        for(int i = 1; i < k; i++) {
            ans = min(ans,costs[n-1][i]);
        }
        return ans;
    }
};