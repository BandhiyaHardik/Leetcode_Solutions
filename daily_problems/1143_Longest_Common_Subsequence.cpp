class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        vector<vector<int>> t(2, vector<int>(n+1));
        
        for(int i = 0; i<m+1; i++) {
            for(int j = 0; j<n+1; j++) {
                if(i == 0 || j == 0)
                    t[i%2][j] = 0;
                else if(text1[i-1] == text2[j-1])
                    t[i%2][j] = 1 + t[(i+1)%2][j-1];
                else
                    t[i%2][j] = max(t[i%2][j-1], t[(i+1)%2][j]);
            }
        }
        
        return t[m%2][n];
    }
};