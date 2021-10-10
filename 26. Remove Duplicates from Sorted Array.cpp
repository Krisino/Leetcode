class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        int left = 0, right = 1;
        while(right < nums.size()){
            if(nums[left] == nums[right]) {
                right++;
            }else{
                nums[left + 1] = nums[right];
                left++;
            }
        }
        return left + 1;
    }
};