class Solution {
public:
    int t[101][101];
        
    int solve(int m, int n, int i, int j) {
        if(i >= m || j >= n || i < 0 || j < 0)
            return 0;
        
        if(i == m-1 && j == n-1)
            return 1;
        
        if(t[i][j] != -1)
            return t[i][j];
        
        return t[i][j] = solve(m, n, i+1, j) + solve(m, n, i, j+1);
        
    }
    
    int uniquePaths(int m, int n) {
        memset(t, -1, sizeof(t));
        
        return solve(m, n, 0, 0);
    }
};