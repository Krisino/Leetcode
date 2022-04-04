class Solution {
public:
    bool judge(int n) {
        int temp = n;
        while(temp) {
            if(temp % 10 == 0 || n % (temp % 10) != 0) {
                return false;
            }
            temp /= 10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i <= right; i++) {
            if(judge(i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};