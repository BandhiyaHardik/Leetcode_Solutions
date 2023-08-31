class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> taps;
        
        for (int i = 0; i <= n; ++i) {
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);
            taps.push_back({left, right});
        }
        
        sort(taps.begin(), taps.end());
        
        int tapsUsed = 0;
        int currentRight = 0; 
        int idx = 0; 
        
        while (currentRight < n) {
            int maxRight = currentRight; 
            
            while (idx <= n && taps[idx].first <= currentRight) {
                maxRight = max(maxRight, taps[idx].second);
                idx++;
            }

            if (maxRight == currentRight) {
                return -1;
            }
            
            currentRight = maxRight;
            tapsUsed++;
        }
        
        return tapsUsed;
    }
};
