class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = 0;
        while(right <= s.length()){
            right++;
            if(s[right] == ' '|| s[right] == '\0'){
                int pos = right + 1;
                while(left < right){
                    swap(s[left], s[right-1]);
                    left++;
                    right--;
                }
                left = pos;
                right = pos;
            }
        }
        return s;
    }
};