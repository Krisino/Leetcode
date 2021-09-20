class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int m = mat.size();
        if(m == 0)  return ans;
        int n = mat[0].size();
        if(n == 0)  return ans;
        bool flag = true;
        int row,col;
        for(int i = 0; i < m + n - 1;i++){
            if(flag){
                row = i < m ? i : m - 1;
                col = i - row;
            }else{
                col = i < n ? i : n - 1;
                row = i - col;
            }
            while(row>=0&&row<m&&col>=0&&col<n){
                ans.push_back(mat[row][col]);
                row = flag ? row - 1 : row + 1;
                col = flag ? col + 1 : col - 1;
            }
            flag = !flag;
        }
        return ans;
    }
};