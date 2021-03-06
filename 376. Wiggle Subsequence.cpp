class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1) {
            return nums.size();
        }
        int preDiff = 0;
        int curDiff = 0;
        int result = 1; // The first one is also a part of the wiggle sequence
        for(int i = 1; i < nums.size(); i++) {
            curDiff = nums[i] - nums[i - 1];
            if((curDiff > 0 && preDiff <= 0) || (curDiff < 0 && preDiff >= 0)) {
                result++;
                preDiff = curDiff;
            }
        }
        return result;
    }
};