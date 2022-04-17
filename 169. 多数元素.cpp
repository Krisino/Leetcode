class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand_num = nums[0];
        int count = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == cand_num) {
                count++;
            } else {
                count--;
                if(count == 0) {
                    cand_num = nums[i];
                    count = 1;
                }
            }
        }
        return cand_num;
    }
};