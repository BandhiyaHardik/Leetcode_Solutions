class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.length();
        
        int mp[26] = {0};
        
        for(int i = 0; i<n; i++) {
            mp[s[i] - 'a']++;
            mp[t[i] - 'a']--;
        }

        int result = 0;

        for(int i = 0; i < 26; i++) {
            result += max(0, mp[i]);
        } 
        
        return result;
    }
};
