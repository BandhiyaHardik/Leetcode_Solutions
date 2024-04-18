class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int perimeter = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 0)
                    continue;
                
                if(i-1 < 0 || grid[i-1][j] == 0) 
                    perimeter++;
                
                if(i+1 >= m || grid[i+1][j] == 0) 
                    perimeter++;
                
                if(j-1 < 0 || grid[i][j-1] == 0) 
                    perimeter++;
                
                if(j+1 >= n || grid[i][j+1] == 0) 
                    perimeter++;
                
            }
        }
        
        return perimeter;
    }
};