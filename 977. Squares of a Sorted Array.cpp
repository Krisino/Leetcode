class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int head = 0,tail = nums.size()-1,i = nums.size()-1;
        while(head <= tail){
            if(abs(nums[head])>abs(nums[tail])){
                ans[i--] = nums[head] * nums[head];
                head++;
            }else{
                ans[i--] = nums[tail] * nums[tail];
                tail--;
            }
        }
        return ans;
    }
};