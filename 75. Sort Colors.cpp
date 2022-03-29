class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int pointer = 0;
        while(pointer <= right) {
            if(nums[pointer] == 2) {
                swap(nums[pointer], nums[right]);
                right--;
            } else if(nums[pointer] == 0) {
                swap(nums[pointer], nums[left]);
                left++;
                pointer++;
            } else {
                pointer++;
            }
        }
    }
};