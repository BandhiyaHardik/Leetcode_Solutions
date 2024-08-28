class Solution {
public:
    bool checkSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        if(i < 0 || i >= grid1.size() || j < 0 || j >= grid1[0].size()) {
            return true;
        }
        
        if(grid2[i][j] != 1) {
            return true;
        }

        grid2[i][j] = -1;

        bool result = (grid1[i][j] == 1);

        result = result & checkSubIsland(grid1, grid2, i+1, j);
        result = result & checkSubIsland(grid1, grid2, i-1, j);
        result = result & checkSubIsland(grid1, grid2, i, j+1);
        result = result & checkSubIsland(grid1, grid2, i, j-1);

        return result;

    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        //DFS
        int subIslands = 0;
        int m = grid2.size();
        int n = grid2[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid2[i][j] == 1 && checkSubIsland(grid1, grid2, i, j)) {
                    subIslands++;
                }
            }
        }

        return subIslands;
    }
};
