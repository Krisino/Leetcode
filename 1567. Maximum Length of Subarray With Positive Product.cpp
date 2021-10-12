class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int positivePos = 0;
        int negativePos = 0;
        if(nums[0] > 0) {
            positivePos = 1;
        } else if (nums[0] < 0) {
            negativePos = 1;
        }
        int ans = positivePos;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > 0) {
                positivePos = positivePos + 1;
                negativePos = negativePos > 0 ? negativePos + 1 : 0;
            } else if (nums[i] < 0) {
                int positivePosCopy = positivePos;
                positivePos = negativePos > 0 ? negativePos + 1 : 0;
                negativePos = positivePosCopy + 1;
            } else {
                positivePos = 0;
                negativePos = 0;
            }
            ans = max(ans, positivePos);
        }
        return ans;
    }
};