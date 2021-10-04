class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans = "";
        int count = 0;
        for(int i = s.length() - 1; i >= 0 ; i--){
            if(s[i] == '-'){
                continue;
            }else if(s[i] >= 'a' && s[i] <= 'z'){
                s[i] -= 32;
            }
            ans.append(1,s[i]);
            count++;
            if(count % k == 0 && count != 0){
                ans.append(1,'-');
            }
        }
        if(ans == "") return ans;
        if(count % k == 0){
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};