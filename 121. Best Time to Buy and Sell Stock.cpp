class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0],profit = 0;
        for(int i = 1; i < prices.size(); i++){
            minPrice = minPrice < prices[i]?minPrice:prices[i];
            profit = profit > prices[i] - minPrice?profit:prices[i] - minPrice;
        }
        return profit;
    }
};
