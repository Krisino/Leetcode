class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int pre = values[0] + 0;
        int result = INT_MIN;
        for(int i = 1; i < values.size(); i++) {
            result = max(result, pre + values[i] - i);
            pre = max(pre, values[i] + i);
        }
        return result;
    }
};