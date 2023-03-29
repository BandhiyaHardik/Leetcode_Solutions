class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i-1>=j) {
                    dp[i][j]=max(dp[i-1][j-1]+j*satisfaction[i-1],dp[i-1][j]);
                } else {
                    dp[i][j]=dp[i-1][j-1]+j*satisfaction[i-1];
                }
            }
        }
        
        int maxVal=0;
        for(int i=0;i<=n;i++){
            if(dp[n][i]>maxVal) {
                maxVal=dp[n][i];
            }
        }    
        return maxVal;
    }
};