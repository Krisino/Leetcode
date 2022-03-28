class Solution {
public:
    bool hasAlternatingBits(int n) {
        int diff = n & 1;
        n >>= 1;
        for(int i = 1; n > 0; i++) {
            if(n & 1 ^ diff == 0) {
                return false;
            }
            diff = n & 1;
            n >>= 1;
        }
        return true;
    }
};