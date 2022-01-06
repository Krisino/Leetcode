class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 用于存储已经记录的数据
        unordered_map<int, int>mp;
        for(int i = 0; i < nums.size(); i++) {
            // 在 unordered_map 中查找是否有与 nums[i] 配对的数
            auto res = mp.find(nums[i]);
            // 若找到则返回下标
            // 若找不到则在 unordered_map 中记录需要配对的数和自己的下标
            if(res != mp.end()) {
                return {res->second, i};
            } else {
                mp.insert(pair<int, int>(target - nums[i], i));
            }
        }
        // 若不存在可以配对的情况，返回-1, -1
        return {-1, -1};
    }
};