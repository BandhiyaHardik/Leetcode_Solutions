class Solution {
public:
    int m, n, N;
    int t[101][101][201];
    
    bool solve(int i, int j, int k, string& s1, string& s2, string& s3) {
        
        if(i == m && j == n && k == N) {
            return true;
        }
        
        if(k >= N) 
            return false;
        
        if(t[i][j][k] != -1)
            return t[i][j][k];
        
        bool result = false;
        
        if(i < m && s1[i] == s3[k]) {
            result = solve(i+1, j, k+1, s1, s2, s3);
        }
        
        if(result == true)
            return t[i][j][k] = result;
        
        if(j < n && s2[j] == s3[k]) {
            result = solve(i, j+1, k+1,s1, s2, s3);
        }
        return t[i][j][k] = result; 
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        m = s1.length();
        n = s2.length();
        N = s3.length();
        memset(t, -1, sizeof(t));
        return solve(0, 0, 0, s1, s2, s3);
    }
};