class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int result = 0;
        
        for(int row = 0; row < m; row++) {
            
            for(int col = 0; col < n; col++) {
                
                if(matrix[row][col] == 1 && row > 0) {
                    matrix[row][col] += matrix[row-1][col];
                }
                
            }
            
            vector<int> currRow = matrix[row];
            sort(begin(currRow), end(currRow), greater<int>());
            for(int col = 0; col < n; col++) {
                int base   = (col+1);
                int height = currRow[col];
                
                result = max(result, base*height);
            }
            
        }
        
        return result;
    }
};
