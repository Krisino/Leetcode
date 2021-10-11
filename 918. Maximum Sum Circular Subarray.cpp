class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0];
        int minSum = nums[0];
        int maxValue = nums[0];
        int minValue = nums[0];
        int sum = nums[0];
        for(int i = 1; i < n; i++) {
            maxSum = max(maxSum + nums[i],nums[i]);
            maxValue = max(maxValue, maxSum);
            minSum = min(minSum + nums[i], nums[i]);
            minValue = min(minValue, minSum);
            sum += nums[i];
        }
        if(sum - minValue == 0) {
            return maxValue;
        } else {
            return max(maxValue, (sum - minValue));
        }
    }
};