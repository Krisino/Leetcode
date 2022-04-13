class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        int n = nums.size();
        vector<int> pre_sum(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            pre_sum[i] = pre_sum[i - 1] + nums[i - 1];
            if(mp.find(pre_sum[i] - k) != mp.end()) {
                count += mp[pre_sum[i] - k];
            }
            if(mp.find(pre_sum[i]) != mp.end()) {
                mp[pre_sum[i]]++;
            } else {
                mp[pre_sum[i]] = 1;
            }
        }
        return count;
    }
};