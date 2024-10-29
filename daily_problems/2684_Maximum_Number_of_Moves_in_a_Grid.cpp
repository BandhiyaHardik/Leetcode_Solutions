class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for (int row = 0; row < m; ++row) {
            dp[row][0] = 1;
        }

        int max_moves = 0;

        for (int col = 1; col < n; ++col) {
            for (int row = 0; row < m; ++row) {
                if (row > 0 && grid[row][col] > grid[row - 1][col - 1] && dp[row - 1][col - 1]) {
                    dp[row][col] = max(dp[row][col], dp[row - 1][col - 1] + 1);
                }
                if (grid[row][col] > grid[row][col - 1] && dp[row][col - 1]) {
                    dp[row][col] = max(dp[row][col], dp[row][col - 1] + 1);
                }
                if (row < m - 1 && grid[row][col] > grid[row + 1][col - 1] && dp[row + 1][col - 1]) {
                    dp[row][col] = max(dp[row][col], dp[row + 1][col - 1] + 1);
                }
                max_moves = max(max_moves, dp[row][col] - 1);
            }
        }
        
        return max_moves;
    }
};
