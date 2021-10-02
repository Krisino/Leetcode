class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int slow = 0;
        while(slow < nums.size() && nums[slow] != 1) slow++;
        int fast = slow;
        int ans = 0;
        while(fast < nums.size()){
            if(nums[fast] == 0){
                slow = fast + 1;
            }else{
                ans = ans > fast - slow + 1 ? ans : fast - slow + 1;
            }
            fast++;
        }
        return ans;
    }
};