class Solution {
public:
// Version 1
    // void moveZeroes(vector<int>& nums) {
    //     vector<int> nums_new;
    //     int count = 0;
    //     for(int num:nums){
    //         if(num == 0){
    //             count ++;
    //         }else{
    //             nums_new.push_back(num);
    //         }
    //     }
    //     while(count--){
    //         nums_new.push_back(0);
    //     }
    //     nums = nums_new;
    // }
// Version 2
    void moveZeroes(vector<int>& nums) {
        if(nums.size()<=1){
            return;
        }
        int index = 0;
        for(int i = 0;i < nums.size(); i++){
            if(nums[i] != 0){
                nums[index++] = nums[i];
            }
        }
        for(int i = index;i < nums.size(); i++){
            nums[i] = 0;
        }
    }
};
