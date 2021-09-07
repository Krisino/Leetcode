class Solution {
public:
// Version 1: stack
    // int balancedStringSplit(string s) {
    //     stack<char> stk;
    //     int ans = 0;
    //     for(auto c: s){
    //         if(stk.empty()){
    //             stk.push(c);
    //         }else{
    //             if(stk.top() == c){
    //                 stk.push(c);
    //             }else{
    //                 stk.pop();
    //                 if(stk.empty()) ans++;
    //             }
    //         }
    //     }
    //     return ans;
    // }
// Version 2: greedy algorithm
    int balancedStringSplit(string s) {
        int ans = 0, distance = 0;
        for(auto c:s){
            c == 'L'? distance++:distance--;
            if(distance == 0) ans++;
        }
        return ans;
    }
};
