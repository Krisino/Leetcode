class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        if(n < 3) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i++) {
            for(int j = i + 1; j < n - 1; j++) {
                int left = j + 1;
                // right = n 是表示区间内都可以构成三角形
                int right = n;
                // 找到第一个不满足三角形条件的位置
                while(left < right) {
                    int mid = left + (right - left) / 2;
                    if(nums[mid] < nums[i] + nums[j]) {
                        left = mid + 1;
                    } else {
                        right = mid;
                    }
                }
                ans = ans + (left - j - 1);
            }
        }
        return ans;
    }
};