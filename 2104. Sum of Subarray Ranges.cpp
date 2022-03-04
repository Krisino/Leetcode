class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long result = 0;
        for(int i = 0; i < nums.size(); i++) {
            long long curMin = nums[i];
            long long curMax = nums[i];
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[j] < curMin) {
                    curMin = nums[j];
                }
                if(nums[j] > curMax) {
                    curMax = nums[j];
                }
                result += curMax - curMin;
            }
        }
        return result;
    }
};