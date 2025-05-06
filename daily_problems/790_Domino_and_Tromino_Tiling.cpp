class Solution {
public:
    int M = 1000000007;
    int t[1001];
    int solve(int n) {
         if(n == 1 || n == 2)
            return n;
        if(n == 3)
            return 5;
        
        if(t[n] != -1)
            return t[n];
        
        return t[n] = (2*solve(n-1)%M + solve(n-3)%M)%M;
    }
    
    int numTilings(int n) {
       
        memset(t, -1, sizeof(t));
        
        
        return solve(n);
        
    }
};
