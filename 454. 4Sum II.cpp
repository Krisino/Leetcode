class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int>mp;
        for(int a: nums1) {
            for(int b: nums2) {
                // 记录 a + b 出现的次数
                mp[a+b]++;
            }
        }
        // ans 为最终答案
        int ans = 0;
        for(int c: nums3) {
            for(int d: nums4) {
                // 如果有相匹配的 c + d 则将 a + b 出现的次数加入到 ans 中
                if(mp.find(0 - (c + d)) != mp.end()) {
                    ans += mp[0 - (c + d)];
                }
            }
        }
        return ans;
    }
};