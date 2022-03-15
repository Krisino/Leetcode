class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        stack<int> stk;
        for(int i = 0; i < height.size(); i++) {
            if(stk.empty() || height[i] < height[stk.top()]) {
                stk.push(i);
            } else if(height[i] == height[stk.top()]) {
                stk.pop();
                stk.push(i);
            } else {
                while(!stk.empty() && height[i] > height[stk.top()]) {
                    int mid = height[stk.top()];
                    stk.pop();
                    if(!stk.empty()) {
                        int h = min(height[i], height[stk.top()]);
                        result += (h - mid) * (i - stk.top() - 1);
                    }
                }
                stk.push(i);
            }
        }
        return result;
    }
};