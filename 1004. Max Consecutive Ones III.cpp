class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        int zeroCount = 0;
        unordered_map<int, int> mp;
        mp[0] = 0;
        for(int i = 1; i <= n; i++) {
            int idx = i - 1;
            if(nums[idx] == 0) {
                zeroCount++;
            }
            if(mp.find(zeroCount - k) != mp.end()) {
                ans = max(ans, idx - mp[zeroCount - k]);
            }
            if(mp.find(zeroCount) == mp.end()) {
                mp[zeroCount] = idx;
            }
        }
        return zeroCount <= k ? n : ans;
    }
};