class Solution {
public:
    int M;
    int N;
    int MOD = 1e9+7;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int t[51][51][51];
    int solve(int maxMove, int startRow, int startColumn) {
        if(startRow < 0 || startRow >= M || startColumn < 0 || startColumn >= N) {
            return 1; 
        }

        if(maxMove <= 0) 
            return 0;

        if(t[maxMove][startRow][startColumn] != -1) {
            return t[maxMove][startRow][startColumn];
        }

        int result = 0;
        for(auto &dir : directions) {
            int x = startRow    + dir[0];
            int y = startColumn + dir[1];
            
            result = (result + solve(maxMove-1, x, y)) % MOD;
        }

        return t[maxMove][startRow][startColumn] = result%MOD;

    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(t, -1, sizeof(t));
        M = m;
        N = n;
        return solve(maxMove, startRow, startColumn);
    }
};
