class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        vector<int> ans(2, 0);
        int width = 0;
        for(int i = 0; i < s.size(); i++) {
            width += widths[s[i] - 'a'];
            if(width > 100) {
                ans[0]++;
                width = widths[s[i] - 'a'];
            }
        }
        if(width != 0) {
            ans[0]++;
            ans[1] = width;
        }
        return ans;
    }
};