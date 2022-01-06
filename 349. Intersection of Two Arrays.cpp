class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // 用于存放结果数据
        unordered_set<int> result_set;
        // 用于存放 nums1 中数据
        unordered_set<int> num_set(nums1.begin(), nums1.end());
        for(int num: nums2) {
            // 如果两个数组有交集，则加入结果中
            if(num_set.find(num) != num_set.end()) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};