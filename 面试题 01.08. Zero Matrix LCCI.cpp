class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    vector<bool> row(matrix.size());
    vector<bool> column(matrix[0].size());
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j]==0){
                row[i]=true;
                column[j]=true;
            }
        }
    }
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(row[i]||column[j]){
                matrix[i][j]=0;
                }
            }
        }
    }
};
