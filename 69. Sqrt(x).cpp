class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) {
            return x;
        }
        long y = x;
        while(y > x/y) {
            y = (y + x/y)/2;
        }
        return int(y);
    }
};