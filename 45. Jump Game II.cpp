class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0;
        int endPos = 0;
        int maxPos =0;
        for(int i = 0; i < nums.size() - 1; i++) {
            maxPos = max(maxPos, nums[i] + i);
            if(i == endPos) {
                endPos = maxPos;
                step++;
            }
        }
        return step;
    }
};