class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        // 将所给数组从小到大排序
        sort(nums.begin(),nums.end());
        // 定义三个指针 i, left, right
        for(int i = 0; i < nums.size(); i++) {
            // 如果 nums[i] > 0 那么就不可能找到三数之和为 0 的组合
            if(nums[i] > 0) {
                return res;
            }
            // 去重操作 nums[i] == nums[i - 1] 表示 i - 1 时已经记录数据到 res 中
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            // 指向 i 的下一个元素
            int left = i + 1;
            // 指向数组末尾元素
            int right = nums.size() - 1;
            while(left < right) {
                // 向左缩减、向右推进、保存数据
                if(nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                }else if(nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                }else {
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // 保存完数据之后再去重
                    while(left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    while(left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    // 两端同时缩减
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};