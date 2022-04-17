class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0;
        int sum = 0;
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0]++;
        for(int i = 1; i <= n; i++) {
            sum += nums[i - 1];
            if(mp.find(sum - goal) != mp.end()) {
                ans += mp[sum - goal];
            }
            mp[sum]++;
        }
        return ans;
    }
};