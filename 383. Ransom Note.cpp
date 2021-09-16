class Solution {
public:
    // Version 1
    // bool canConstruct(string ransomNote, string magazine) {
    //     int arr1[26] = {0},arr2[26] = {0};
    //     bool flag = true;
    //     for(int i = 0; i < ransomNote.size(); i++){
    //         arr1[ransomNote[i] - 'a']++;
    //     }
    //     for(int i = 0;i < magazine.size(); i++){
    //         arr2[magazine[i] - 'a']++;
    //     }
    //     for(int i = 0;i < 26; i++){
    //         if(arr1[i] != 0 && arr2[i]<arr1[i]){
    //             flag = false;
    //             break;
    //         }
    //     }
    //     return flag;
    // }
    // Version 2
        bool canConstruct(string ransomNote, string magazine) {
            int hash[26] = {0};
            for(int i = 0;magazine[i];++i){
            hash[magazine[i]-'a'] ++;
        }
        for(int i = 0;ransomNote[i];++i){
            hash[ransomNote[i]-'a'] --;
            if(hash[ransomNote[i] - 'a'] < 0)return false;
        }
            return true;
    }
};
