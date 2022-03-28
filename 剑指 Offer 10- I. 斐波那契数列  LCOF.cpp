class Solution {
public:
    int fib(int n) {
        const int MOD = 1000000007;
        int f[2];
        f[0] = 0;
        f[1] = 1;
        if(n <= 1) {
            return f[n];
        }
        for(int i = 2; i <= n; i++) {
            int temp = (f[0] + f[1]) % MOD;
            f[0] = f[1];
            f[1] = temp;
        }
        return f[1];
    }
};