class Solution {
public:
    // bool isUnique(string astr) {
    //     if(astr.size() <= 1) {
    //         return true;
    //     }
    //     for(int i = 0; i < astr.size(); i++) {
    //         for(int j = i + 1; j < astr.size(); j++) {
    //             if(astr[i] == astr[j]) {
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }
    
    bool isUnique(string astr) {
        int flag = 0;
        int distance = 0;
        for(int i = 0; i < astr.length(); i++) {
            distance = astr[i] - 'a';
            if((flag & (1 << distance)) != 0) {
                return false;
            } else {
                flag |= (1 << distance);
            }
        }
        return true;
    }
};