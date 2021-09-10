class Solution {
    vector<vector<int>> ans;
public:
    void permutation(vector<int>& nums, int pos){
        if(pos == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = pos;i < nums.size(); i++){
            swap(nums[pos], nums[i]);
            permutation(nums, pos + 1);
            swap(nums[pos], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        permutation(nums,0);
        return ans;
    }
};
