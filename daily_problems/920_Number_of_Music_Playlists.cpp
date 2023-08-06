class Solution {
public:
    int N;
    int GOAL;
    int K;
    long t[101][101];
    const int MOD = 1e9+7;
    
    long solve(int count_song, int count_unique) {
        if(count_song == GOAL) {
            if(count_unique == N)
                return 1;
            
            return 0;
        }
        
        if(t[count_song][count_unique] != -1)
            return t[count_song][count_unique];
        
        long result = 0;

        if(count_unique < N)
            result += (N-count_unique) * solve(count_song+1, count_unique+1);

        if(count_unique > K)
            result += (count_unique - K) * solve(count_song+1, count_unique);
        
        
        return t[count_song][count_unique] = result % MOD;

    }
    
    int numMusicPlaylists(int n, int goal, int k) {
        N    = n;
        GOAL = goal;
        K    = k;
        memset(t, -1, sizeof(t));
        return solve(0, 0); 
    }
};
