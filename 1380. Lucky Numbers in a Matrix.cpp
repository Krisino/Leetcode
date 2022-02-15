class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        vector<int> result;
        for(int i = 0; i < rowSize; i++) {
            int minPos = 0;
            for(int j = 0; j < colSize; j++) {
                if(matrix[i][j] < matrix[i][minPos]) {
                    minPos = j;
                }
            }
            bool isLuckyNumbers = true;
            for(int k = 0; k < rowSize; k++) {
                if(matrix[i][minPos] < matrix[k][minPos]) {
                    isLuckyNumbers = false;
                    break;
                }
            }
            if(isLuckyNumbers) {
                result.push_back(matrix[i][minPos]);
            }
        }
        return result;
    }
};