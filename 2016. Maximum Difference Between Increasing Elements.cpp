class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int result = -1;
        int minNum = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > minNum && nums[i] - minNum > result){
                result = nums[i] - minNum;
            }
            if(nums[i] < minNum) {
                minNum = nums[i];
            }
        }
        return result;
    }
};