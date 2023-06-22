class Solution {
public:
    int t[50001][2];
    int FEE;
    int maxP(vector<int>& prices, int day, int n, int buy) {
        if(day >= n)
            return 0;
        
        int profit = 0;
        if(t[day][buy] != -1) {
            return t[day][buy];
        }
        //buy
        if(buy) {
            int consider      = maxP(prices, day+1, n, false) - prices[day];
            int not_consider  = maxP(prices, day+1, n, true);
            profit = max({profit, consider, not_consider});
        } else { //sell
            int consider      = maxP(prices, day+1, n, true) + prices[day] - FEE;
            int not_consider  = maxP(prices, day+1, n, false);
            profit = max({profit, consider, not_consider}); 
        }
        
        return t[day][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
         int n = prices.size();
        memset(t, -1, sizeof(t));
        FEE = fee;
        return maxP(prices, 0, n, true);
    }
};
