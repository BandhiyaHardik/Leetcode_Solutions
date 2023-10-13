class Solution {
public:
    int t[1001];
    int solve(vector<int>& cost, int idx) {
        if(idx >= cost.size())
            return 0;
        if(t[idx] != -1)
            return t[idx];
			
        int move_one = cost[idx] + solve(cost, idx+1);
        int move_two = cost[idx] + solve(cost, idx+2);
        
        return t[idx] = min(move_one, move_two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memset(t, -1, sizeof(t));
        return min(solve(cost, 0), solve(cost, 1));
    }
};