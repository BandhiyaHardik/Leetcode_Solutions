class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> temp = matrix;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    for (int k = 0; k < n; k++) {
                        temp[i][k] = 0;
                    }
                    for (int k = 0; k < m; k++) {
                        temp[k][j] = 0;
                    }
                }
            }
        }

        matrix = temp;
    }
};