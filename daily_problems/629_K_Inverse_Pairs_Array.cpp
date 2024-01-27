class Solution {
public:
    const int M = 1e9+7;
    int kInversePairs(int n, int k) {
        vector<vector<int>> t(n+1, vector<int>(k+1));

        for(int i = 0; i < n+1; i++) {
            t[i][0] = 1;
        }

        for(int i = 1; i<=n; i++) {
            
            for(int j = 1; j <= k; j++) {

                for(int inv = 0; inv <= min(i-1, j); inv++) {
                    t[i][j] = (t[i][j] + t[i-1][j-inv])%M;
                }

            }
        }
        return t[n][k];
    }
};