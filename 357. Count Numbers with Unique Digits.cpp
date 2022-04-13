class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) {
            return 1;
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(i == 1) {
                ans += 10;
            } else {
                int temp = 9;
                int base = 9;
                for(int j = 2; j <= i; j++) {
                    temp *= base;
                    base--;
                }
                ans += temp;
            }
        }
        return ans;
    }
};