class Solution {
public:
    int n;
    int t[301][5001];
    
    int solve(int i, vector<int>& coins, int amount) {
        
        if(amount == 0)
            return t[i][amount] = 1;
        
        if(i == n || amount < 0)
            return 0;
        
         if(t[i][amount] != -1)
            return t[i][amount];
        
        if(coins[i] > amount)
            return t[i][amount] = solve(i+1, coins, amount);
        
        int take = solve(i, coins, amount-coins[i]);
        int skip = solve(i+1, coins, amount);
        
        return t[i][amount] = take+skip;
        
    }
    
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        memset(t, -1, sizeof(t));
        return solve(0, coins, amount);
    }
};
