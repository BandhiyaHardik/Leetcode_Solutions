class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        vector<int> prev(n);
        for(int col = 0; col<n; col++)
            prev[col] = A[0][col];
        
        for(int row = 1; row<n; row++) {
            vector<int> curr(n);
            for(int col = 0; col<n; col++) {
                curr[col] = A[row][col] + min({prev[max(0, col-1)],  prev[col],  prev[min(n-1, col+1)]});
            }
            prev = curr;
        }
        return *min_element(prev.begin(), prev.end());
    }
};