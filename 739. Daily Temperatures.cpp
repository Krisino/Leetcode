class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        vector<int> result(len, 0);
        stack<int> stk;
        for(int i = 0; i < len; i++) {
            if(stk.empty() || temperatures[i] <= temperatures[stk.top()]) {
                stk.push(i);
            } else {
                while(!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                    result[stk.top()] = i - stk.top();
                    stk.pop();
                }
                stk.push(i);
            }
        }
        return result;
    }
};