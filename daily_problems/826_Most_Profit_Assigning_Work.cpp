class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();
        
        vector<pair<int, int>> vec;
        for(int i = 0; i < n; i++) {
            vec.push_back({difficulty[i], profit[i]});
        }

        sort(begin(vec), end(vec));

        sort(begin(worker), end(worker));

        int totalProfit = 0;
        int j = 0;
        int maxProfit = 0;
    
        for(int i = 0; i < m; i++) {
            
            while(j < n && worker[i] >= vec[j].first) {
                maxProfit = max(maxProfit, vec[j].second);
                j++;
            }

            totalProfit += maxProfit;

        }

        return totalProfit;
    }
};