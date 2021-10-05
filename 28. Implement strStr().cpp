class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
        int len = needle.length();
        int arr[len];
        memset(arr,0,sizeof(arr));
        int index = 0;
        for(int i = 1; i < len;){
            if(needle[index] == needle[i]){
                arr[i] = index + 1;
                i++;
                index++;
            }else{
                if(index != 0){
                    index = arr[index - 1];
                }else{
                    arr[i] = 0;
                    i++;
                }
            }
        }
        int i = 0;
        int j = 0;
        while(i < haystack.length() && j < needle.length()){
            if(haystack[i] == needle[j]){
                i++;
                j++;
            }else{
                if(j != 0){
                    j = arr[j - 1];
                }else{
                    i++;
                }
            }
        }
        if(j == needle.length()){
            return i - j;
        }
        return -1;
    }
};