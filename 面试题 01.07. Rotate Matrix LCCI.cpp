class Solution {
public:
    // Version 1
    // void rotate(vector<vector<int>>& matrix) {
    //     auto matrix_new = matrix;
    //     for(int i = 0;i < matrix.size(); i++){
    //         for(int j = 0; j < matrix.size(); j++){
    //             matrix_new[j][matrix.size()-1-i] = matrix[i][j];
    //         }
    //     }
    //     matrix = matrix_new;
    // }
    // Version 2
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        if(size == 0) return;
        // Max row serial number
        int r = (size>>1)-1;
        // Max col serial number
        int c = (size-1)>>1;
        for(int i = r; i >= 0; i--){
            for(int j = c; j >= 0; j--){
                swap(matrix[i][j],matrix[j][size-1-i]);
                swap(matrix[i][j],matrix[size-1-i][size-1-j]);
                swap(matrix[i][j],matrix[size-1-j][i]);
            }
        }
    }

};