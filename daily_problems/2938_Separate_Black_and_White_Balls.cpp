class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.length();

        long long swap  = 0;
        int black = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == '0') {
                swap += black;
            } else {
                black++;
            }
        }

        return swap;
    }
};