class Solution {
public:
    // 与Leetcode 15. 三数之和类似，添加一层循环
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for(int j = i + 1; j< size; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int left = j + 1;
                int right = size - 1;
                while(left < right) {
                    // 防止相加和溢出
                    if(nums[i] + nums[j] < target - (nums[left] + nums[right])) {
                        left++;
                    } else if (nums[i] + nums[j] > target - (nums[left] + nums[right])) {
                        right--;
                    } else {
                        res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        while(left < right && nums[right] == nums[right - 1]) {
                            right--;
                        }
                        while(left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        left++;
                        right--;
                    }
                }
            }
        }
        return res;
    }
};