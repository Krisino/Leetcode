class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int pre = 0, count = 0;
        for(auto num: nums) {
            count++;
            if(num == 0) {
                pre = count;
                count = 0;
            }
            ans = max(ans, pre + count);
        }
        return ans;
    }
};