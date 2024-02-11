class Solution {
public:
    int m, n;
    int t[71][71][71];
    vector<int> colDir{-1, 0, 1};
    bool isSafe(int& i) {
        return i >= 0 && i < n;
    }
    
    int solve(vector<vector<int>>& grid, int row, int c1, int c2) {
        if(row >= m)
            return 0;
        
        
        if(t[row][c1][c2] != -1) {
            return t[row][c1][c2];
        }
        
        int count = grid[row][c1];
        if(c1 != c2) {
            count += grid[row][c2];
        }
        
        
        int ans = 0;
        for(int& x : colDir) {
            for(int& y : colDir) {
                
                int c1_ = x + c1;
                int c2_ = y + c2;
                
                if(isSafe(c1_) && isSafe(c2_)) {
                    ans = max(ans, solve(grid, row+1, c1_, c2_));
                }
            }
        }
        
        return t[row][c1][c2] = count+ans;  
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(t, -1, sizeof(t));
        return solve(grid, 0, 0, n-1);
    }
};