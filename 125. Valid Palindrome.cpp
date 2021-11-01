class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        int left = 0;
        int right = len - 1;
        while(left < right) {
            while(left < len){
                if(s[left] < '0') {
                    left++;
                } else if (s[left] > '9' && s[left] < 'A') {
                    left++;
                } else if (s[left] >= 'A' && s[left] <= 'Z') {
                    s[left] += 32;
                } else if (s[left] > 'Z' && s[left] < 'a') {
                    left++;
                } else if (s[left] > 'z') {
                    left++;
                }else {
                    break;
                }
            }
            while(right >= 0) {
                if(s[right] < '0') {
                    right--;
                } else if (s[right] > '9' && s[right] < 'A') {
                    right --;
                } else if (s[right] >= 'A' && s[right] <= 'Z') {
                    s[right] += 32;
                } else if (s[right] > 'Z' && s[right] < 'a') {
                    right--;
                } else if (s[right] > 'z') {
                    right --;
                } else {
                    break;
                }
            }
            if (left < right && s[left] != s[right]) {
                return false;
            } else {
                left++;
                right--;
            }
        }
        return true;
    }
};