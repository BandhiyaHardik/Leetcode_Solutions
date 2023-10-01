class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            
            if (s[i] != ' ') {
                
                int j = i;
                
                while( j < n && s[j] != ' ') {
                    j++;
                }
                
                reverse(s.begin() + i, s.begin() + j);
                
                i = j;
            }
            
        }
        
        return s;
    }
};_