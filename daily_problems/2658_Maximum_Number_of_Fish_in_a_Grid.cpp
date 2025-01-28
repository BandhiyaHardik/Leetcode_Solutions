class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int dfs(int i, int j, vector<vector<int>>& grid) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return 0;
        }

        int fishCount = grid[i][j];
        grid[i][j] = 0;

        for(vector<int>& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            fishCount += dfs(i_, j_, grid);
        }

        return fishCount;

    }

    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int maxFish = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)  {
                if(grid[i][j] > 0) {
                    maxFish = max(maxFish, dfs(i, j, grid));
                }
            }
        }

        return maxFish;
    }
};
