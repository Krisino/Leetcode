class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size());
        stack<int> st;
        for(int i = 0;i<temperatures.size();i++){
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                int idx = st.top();
                st.pop();
                ans[idx] = i - idx;
            }
                st.push(i);
        }
        return ans;
    }
};