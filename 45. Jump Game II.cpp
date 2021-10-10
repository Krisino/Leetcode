class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0;
        int start = 0;
        int end = 1;
        while(end < nums.size()){
            int maxPos = 0;
            for(int i = start; i < end; i++){
                maxPos = max(maxPos, i + nums[i]);
            }
            start = end;
            end = maxPos + 1;
            step++;
        }
        return step;
    }
};