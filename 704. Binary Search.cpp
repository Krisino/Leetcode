class Solution {
public:
    // 方式一：
    // 使用左闭右闭区间 [left, right], left == right 时有意义, while() 条件应该为 <=
    // int search(vector<int>& nums, int target) {
    //     int left = 0;
    //     int right = nums.size() - 1;
    //     // 当[left, right] 都为闭区间
    //     while (left <= right) {
    //         // 防止溢出
    //         int middle = left + ((right - left) >> 1);
    //         if(nums[middle] < target) {
    //             left = middle + 1;
    //         } else if(nums[middle] > target) {
    //             right = middle - 1;
    //         } else {
    //             return middle;
    //         }
    //     }
    //     return -1;
    // }

    // 方式二：
    // 使用左闭右开区间 [left, right), left == right 时无意义, while() 条件应该为 <
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        // 当[left, right) 为左闭右开区间
        while (left < right) {
            // 防止溢出
            int middle = left + ((right - left) >> 1);
            if(nums[middle] < target) {
                left = middle + 1;
            } else if(nums[middle] > target) {
                right = middle;
            } else {
                return middle;
            }
        }
        return -1;
    }
};