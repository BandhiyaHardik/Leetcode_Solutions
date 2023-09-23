class Solution {
public:
    bool predecessor(string& prev, string& curr) {
        int m = prev.length();
        int n = curr.length();
        
        if(m >= n || n-m != 1)
            return false;
        
        int i = 0, j = 0;
        while(i < m && j < n) {
            if(prev[i] == curr[j]) {
                i++;
            }
            j++;
        }
        return i==m;
    }
    
    static bool myFunction(string& s1, string& s2) {
        return s1.length() < s2.length();
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(begin(words), end(words), myFunction); 
        
        vector<int> t(n, 1);
        int maxL = 1;
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<i; j++) {
                
                if(predecessor(words[j], words[i])) {
                    t[i] = max(t[i], t[j]+1);
                    maxL = max(maxL, t[i]);
                }
            }
        }
        
        return maxL;
        
    }
};