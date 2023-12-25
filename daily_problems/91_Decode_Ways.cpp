class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if(n == 1)
            return s[0] == '0' ? 0 : 1;
        if(s[0] == '0')
            return 0;
        
        int last1 = 1, last2 = 1;
        
        for(int i = 1; i<n; i++) {
            int count = s[i] != '0' ? last1 : 0;
            
            if(s[i-1] == '1' || (s[i-1] == '2' && s[i] < '7'))
                count += last2;
            
            last2 = last1;
            last1  = count;
        }
        
        return last1;
    }
};