class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        
        int maxLen = 0;
        int currCost = 0;
        
        int i = 0, j = 0;
        while(j < n) {
            currCost += abs(s[j] - t[j]);
            
            while (currCost > maxCost) {
                currCost -= abs(s[i] - t[i]);
                i++;
            }
            
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        
        return maxLen;
    }
};