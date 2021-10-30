class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if (nums.size() == 2) {
            return nums;
        }
        int a_xor_b = 0;
        for(int num: nums) {
            a_xor_b ^= num;
        }
        vector<int> ans(2);
        int mask = 1;
        while((mask & a_xor_b) == 0) {
            mask <<= 1;
        }
        for(int num: nums) {
            if((mask & num) == 0) {
                ans[1] ^= num;
            }else {
                ans[0] ^= num;
            }
        }
        return ans;
    }
};