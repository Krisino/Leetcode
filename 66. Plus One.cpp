class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size() + 1;
        vector<int> ans(len,'0');
        reverse(digits.begin(),digits.end());
        int tmp = 0;
        for(int i = 0; i < len; i++) {
            if(i < len - 1){
                if(i == 0)
                    tmp += digits[i] + 1;
                else{
                    tmp += digits[i];
                }
            }
            ans[i] = tmp %10;
            tmp /= 10;
        }
        if(ans[len - 1] == 0){
            ans.resize(len -1);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};