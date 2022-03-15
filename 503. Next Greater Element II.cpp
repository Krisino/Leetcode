class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size, -1);
        stack<int> stk;
        for(int i = 0; i < size * 2; i++) {
            while(!stk.empty() && nums[i % size] > nums[stk.top() % size]) {
                result[stk.top() % size] = nums[i % size];
                stk.pop();
            }
            stk.push(i % size);
        }
        return result;
    }
};