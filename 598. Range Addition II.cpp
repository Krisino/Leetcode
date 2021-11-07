class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
    // In fact we need to return the min_x * min_y in the ops due to the overlaps
        int min_x = m;
        int min_y = n;
        for(int i = 0; i < ops.size(); i++) {
            if(ops[i][0] < min_x) {
                min_x = ops[i][0];
            }
            if(ops[i][1] < min_y) {
                min_y = ops[i][1];
            }
        }
        return min_x*min_y;
    }
};