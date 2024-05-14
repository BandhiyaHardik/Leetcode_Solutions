class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int DFS(vector<vector<int>>& grid, int i, int j) {

        if(i >= m || i < 0 || j >= n || j < 0 || grid[i][j] == 0) {
            return 0;
        }

        int originalGoldValue = grid[i][j];
        grid[i][j] = 0;

        int maxGold = 0;

        for(vector<int>& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            maxGold = max(maxGold, DFS(grid, new_i, new_j));
        }


        grid[i][j] = originalGoldValue;
        return originalGoldValue + maxGold;


    }

    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int maxGold = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] != 0) {

                    maxGold = max(maxGold, DFS(grid, i, j));
                }

            }
        }

        return maxGold;
    }
};