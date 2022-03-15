class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        vector<int> result(nums1.size(), -1);
        unordered_map<int, int> mp;
        for(int i = 0; i < nums1.size(); i++) {
            mp[nums1[i]] = i;
        }
        for(int i = 0; i < nums2.size(); i++) {
            if(stk.empty() || nums2[i] <= nums2[stk.top()]) {
                stk.push(i);
            } else {
                while(!stk.empty() && nums2[i] > nums2[stk.top()]) {
                    if(mp.find(nums2[stk.top()]) != mp.end()) {
                        result[mp[nums2[stk.top()]]] = nums2[i];
                    }
                    stk.pop();
                }
                stk.push(i);
            }
        }
        return result;
    }
};