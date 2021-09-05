class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.empty()){
            return -1;
        }
        int left_sum = 0,right_sum = accumulate(nums.begin()+1,nums.end(),0);
        for(int i = 0;i<nums.size();i++){
            if(i>0){
                left_sum+=nums[i-1];
                right_sum-=nums[i];
            }
            if(left_sum == right_sum){
                return i;
            }
        }
        return -1;
    }
};