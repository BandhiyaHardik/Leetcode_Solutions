class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> result(begin(prices), end(prices));

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(prices[j] <= prices[i]) {

                    result[i] -= prices[j];
                    break;
                }
            }
        }

        return result;
    }
};
