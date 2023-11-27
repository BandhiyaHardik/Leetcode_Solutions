class Solution {
public:
    
    int M = 1e9+7;
    vector<vector<int>> adj = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };
    
    int knightDialer(int n) {
        int result = 0;
        
        vector<vector<int>> t(n, vector<int>(10));
        for(int cell = 0; cell < 10; cell++) {
            t[0][cell] = 1; 
        }
        
        for(int i = 1; i < n; i++) {  
            
            for(int cell = 0; cell <= 9; cell++) {    
                int ans = 0;
                for(int &nextCell : adj[cell]) {
                    
                    ans = (ans + t[i-1][nextCell]) % M;
                    
                }
                t[i][cell] = ans;
                
            }
            
        }
        
        for(int cell = 0; cell <= 9; cell++) {
            result = (result + t[n-1][cell]) % M;
        }
        
        return result;
    }
};