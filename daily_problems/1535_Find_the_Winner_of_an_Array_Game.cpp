class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int maxEl = *max_element(begin(arr), end(arr));
        
        if(k >= n)
            return maxEl;
        
        
        int winner     = arr[0];
        int wins       = 0;
        
        for(int i = 1; i<n; i++) {
            
            if(winner > arr[i]) {
                wins++;
            } else {
                winner = arr[i];
                wins   = 1;
            }
            
            if(wins == k || winner == maxEl) {
                return winner;
            }
            
        }
        
        return winner;
        
    }
};
