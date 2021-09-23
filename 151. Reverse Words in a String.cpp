class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int left = 0, right = s.length() - 1;
        while(s[left] == ' '){
            left++;
        }
        while(s[right] == ' '){
            right--;
        }
        while(left <= right){
            int index = right;
            while(index >= left && s[index] != ' '){
                index -- ;
            }
            for(int i = index + 1; i <= right;i ++ ){
                ans.append(1,s[i]);
            }
            if(index > left){
                ans.append(1,' ');
            }
            while(index >= left && s[index] == ' '){
                index -- ;
            }
            right = index;
        }
        return ans; 
    }
};