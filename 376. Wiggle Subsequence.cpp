class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1){
            return n;
        }
        int ans = 1;
        int preDiff = 0;
        int curDiff;
        for(int i = 1; i < n; i++) {
            curDiff = nums[i] - nums[i-1];
            if((curDiff > 0 && preDiff <= 0) || (curDiff < 0 && preDiff >= 0)) {
                ans++;
                preDiff = curDiff;
            }
        }
        return ans;
    }
};