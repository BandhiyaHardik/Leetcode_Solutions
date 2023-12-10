class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        vector<vector<int>> result(n, vector<int>(m));
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                result[j][i] = A[i][j];
            }
        }
        return result;
    }
};