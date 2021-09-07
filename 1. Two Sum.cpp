class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++){
            auto it = mp.find(nums[i]);
            if(it != mp.end()){
                return vector<int>{it->second,i};
            }else{
                mp[target-nums[i]] = i;
            }
        }
        return vector<int>{-1,-1};
    }
};
