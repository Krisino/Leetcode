class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        int isPrime[32] = {0};
        for(int i = 2; i <= 31; i++) {
            bool isPri = true;
            for(int j = 2; j * j <= i; j++) {
                if(i % j == 0) {
                    isPri = false;
                    break;
                }
            }
            if(isPri) {
                isPrime[i] = 1;
            }
        }

        for(int i = left; i <= right; i++) {
            int cnt = 0;
            int temp = i;
            while(temp != 0) {
                if(temp & 1) {
                    cnt++;
                }
                temp /= 2;
            }
            if(isPrime[cnt]) {
                ans++;
            }
        }
        return ans;
    }
};