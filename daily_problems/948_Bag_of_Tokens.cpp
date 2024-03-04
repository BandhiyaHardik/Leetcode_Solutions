class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        
        int currScore = 0;
        int maxScore  = 0;
        int l = 0, r = n-1;
        
        while(l <= r) {
            if(P >= tokens[l]) {
                currScore++;
                maxScore = max(maxScore, currScore); 
                P -= tokens[l];
                l++;
                
            } else if(currScore >= 1) {
                currScore--;
                P += tokens[r]; 
                r--;
                
            } else {
                return maxScore;
            }
        }
        return maxScore;
    }
};