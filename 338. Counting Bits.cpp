class Solution {
public:
    // Version 1
    // vector<int> countBits(int n) {
    //     vector<int> ans;
    //     for(int i = 0; i <= n; i++){
    //         int count = 0;
    //         int temp = i;
    //         while(temp){
    //             count++;
    //             temp &= (temp - 1);
    //         }
    //         ans.push_back(count);
    //     }
    //     return ans;
    // }

    // Version 2
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        for(int i = 1; i <= n; i++) {
            ans[i] = ans[i >> 1] + (i & 1);
        }
        return ans;
    }
};