class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n), post(n), ans(n);
        pre[0] = nums[0];
        post[n - 1] = nums[n - 1];
        for(int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] * nums[i];
            post[n - 1 - i] = nums[n - 1 - i] * post[n - i];
        }
        ans[0] = post[1];
        ans[n - 1] = pre[n - 2];
        for(int i = 1; i < n - 1; i++) {
            ans[i] = pre[i - 1] * post[i + 1];
        }
        return ans;
    }
};