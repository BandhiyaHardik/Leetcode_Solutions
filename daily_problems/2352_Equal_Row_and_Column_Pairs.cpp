class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        
        int count = 0;
        
        
        for(int r = 0; r<n; r++) {
            
            for(int c = 0; c < n; c++) {
                
                int is_equal = true;
                
                for(int i = 0; i < n; i++) {
                    
                    if(grid[r][i] != grid[i][c]) {
                        is_equal = false;
                        break;
                    }
                    
                }
                
                count += is_equal;
                
            }
            
        }
        
        return count;
        
    }
};