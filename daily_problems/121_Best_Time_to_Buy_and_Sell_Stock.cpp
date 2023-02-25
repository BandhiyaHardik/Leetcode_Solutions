class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int buy = INT_MAX;
        int profit = 0;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i]<buy){
                buy = prices[i];
            }
            profit = max(profit,(prices[i] - buy));
        }
        return profit;
    }
};