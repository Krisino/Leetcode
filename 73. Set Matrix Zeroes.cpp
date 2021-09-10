class Solution {
public:
// Version 1
//     void setZeroes(vector<vector<int>>& matrix) {
//         set<int> row,col;
//         for(int i = 0;i < matrix.size(); i++){
//             for(int j = 0;j < matrix[i].size(); j++){
//                 if(matrix[i][j] == 0){
//                     row.insert(i);
//                     col.insert(j);
//                 }
//             }
//         }
//         for(int i = 0;i < matrix.size(); i++){
//             for(int j = 0;j < matrix[i].size(); j++){
//                 if(row.find(i) != row.end() || col.find(j) != col.end()){
//                     matrix[i][j] = 0;
//                 }
//            }
//         }
//     }
// Version 2
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
