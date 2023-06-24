class Solution {
public:
    int n; 
    int t[21][10003];
    int solve(vector<int>& rods, int i, int diff) {

        if (i == n) {
            if (diff == 0)
                return 0;

            return INT_MIN;
        }
        
        if( t[i][diff+5000] != -1)
            return  t[i][diff+5000];
        
        int ans = 0;

        int nothing     = solve(rods, i + 1 , diff);
        int in_rod_1    = rods[i] + solve(rods, i + 1 , diff + rods[i]);
        int not_in_rod1 = rods[i] + solve(rods, i + 1 , diff - rods[i]);

        return t[i][diff+5000] = max({nothing, in_rod_1, not_in_rod1});
    }
    
    int tallestBillboard(vector<int>& rods) {
        n = rods.size();
        
        memset(t, -1, sizeof(t));
        
        return solve(rods, 0, 0)/2;
    }
};