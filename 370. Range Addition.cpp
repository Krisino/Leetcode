class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> ans(length + 1, 0);
        for(int i = 0; i < updates.size(); i++) {
            int l = updates[i][0];
            int r = updates[i][1];
            int v = updates[i][2];
            ans[l] += v;
            ans[r + 1] -= v;
        }
        for(int i = 1; i < length; i++) {
            ans[i] += ans[i - 1];
        }
        ans.resize(length);
        return ans;
    }
};