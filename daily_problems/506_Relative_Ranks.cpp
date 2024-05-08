class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        
        vector<string> result(n);
        
        unordered_map<int, int> mp;
        
         
        for(int i = 0; i < n; i++) {
            mp[score[i]] = i; 
        }
        
        sort(begin(score), end(score), greater<int>()); 
        
        
        for(int i = 0; i < n; i++) {
            
            if(i == 0) { 
                int ath = mp[score[i]];
                result[ath] = "Gold Medal";
            } else if(i == 1) {
                int ath = mp[score[i]];
                result[ath] = "Silver Medal";
            } else if(i == 2) {
                int ath = mp[score[i]];
                result[ath] = "Bronze Medal";
            } else {
                int ath = mp[score[i]];
                result[ath] = to_string(i+1);
            }
            
        }
        
        return result;
        
    }
};