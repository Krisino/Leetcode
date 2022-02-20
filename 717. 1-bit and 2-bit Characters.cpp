class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int pos = 0;
        while(pos < bits.size() - 1) {
            if(bits[pos] == 0) {
                pos++;
            } else {
                pos += 2;
            }
        }
        return pos == bits.size() - 1;
    }
};