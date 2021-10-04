class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() == 0){
            return "";
        }
        string ans;
        int len;
        for(int center = 0; center < s.length(); center ++){
            len = 1;
            int left = center - 1, right = center + 1;
            while(left >= 0 && s[center] == s[left]){
                left--;
                len++;
            }
            while(right < s.length() && s[center] == s[right]){
                right++;
                len++;
            }
            while(left >= 0 && right < s.length() && s[left] == s[right]){
                left--;
                right++;
                len += 2;
            }
            if(len > ans.size()){
                ans = s.substr(left + 1, len);
            }
        }
        return ans;
    }
};