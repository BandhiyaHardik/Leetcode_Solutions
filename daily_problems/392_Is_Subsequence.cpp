class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m  = t.length();
        int n  = s.length();
        int i = 0, j = 0;

        while(i < m) {
            if(t[i] == s[j])
                j++;
            i++;
        }

        return j == n;
    }
};