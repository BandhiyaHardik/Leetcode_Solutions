class Solution {
public:
    vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1')
            return;
              
        grid[i][j] = '$';
        
        for(pair<int, int> &p : dir) {
            int i_ = i + p.first;
            int j_ = j + p.second;
            dfs(grid, i_, j_);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0)
            return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        
        return count;
    }
};