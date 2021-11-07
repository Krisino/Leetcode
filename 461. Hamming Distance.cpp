class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        int x_xor_y = x^y;
        while(x_xor_y) {
            x_xor_y &= x_xor_y-1;
            count++;
        }
        return count;
    }
};