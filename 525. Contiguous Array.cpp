class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        unordered_map<int, int> mp;
        int diff = nums[0] - (1 - nums[0]);
        mp[0] = -1;
        mp[diff] = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i] == 0) {
                diff -= 1;
            } else {
                diff += 1;
            }
            if(mp.find(diff) != mp.end()) {
                ans = max(ans, i - mp[diff]);
            } else {
                mp[diff] = i;
            }
        }
        return ans;
    }
};