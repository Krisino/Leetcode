class Solution {
public:
    int result;
    int count;

    void traverse(vector<int>& nums, int pos, int sum) {
        if(pos == nums.size()) {
            if(sum > result) {
                result = sum;
                count = 1;
            } else if(sum == result) {
                count++;
            }
            return;
        }
        traverse(nums, pos + 1, sum | nums[pos]);
        traverse(nums, pos + 1, sum);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        result = 0;
        count = 0;
        traverse(nums, 0, 0);
        return count;    
    }
};