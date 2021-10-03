class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int ans = 0;
        int sum = 0;
        for(int j = 0; j < nums.size(); j++){
            sum += nums[j];
            while(sum >= target){
                if(ans == 0){
                    ans = j - i + 1;
                }else{
                    if(ans > j - i + 1){
                        ans = j - i + 1;
                    }
                }
                sum -= nums[i];
                i++;
            }
        }
        return ans;
    }
};