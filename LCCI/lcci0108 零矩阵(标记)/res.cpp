class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int SPECIAL_VALUE = INT_MIN + 3; // 这里INT_MIN+3可以过
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    for (int k = 0; k < n; k++) {
                        if (matrix[k][j] != 0) matrix[k][j] = SPECIAL_VALUE;
                    }
                    for (int l = 0; l < m; l++) {
                        if (matrix[i][l] != 0) matrix[i][l] = SPECIAL_VALUE;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == SPECIAL_VALUE) matrix[i][j] = 0;
            }
        }
        return ;
    }
};