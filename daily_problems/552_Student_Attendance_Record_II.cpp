class Solution {
public:
    int M = 1e9+7;

    int checkRecord(int n) {
        int t[100001][2][3]; 

        for (int A = 0; A <= 1; ++A) {
            for (int L = 0; L <= 2; ++L) {
                t[0][A][L] = 1;
            }
        }

        for(int i = 1; i <= n; i++) {
            for(int A = 0; A <= 1; A++) {
                for(int L = 0; L <= 2; L++) {

                    long long result = t[i-1][A][0];       
                    result += (L < 2 ? t[i-1][A][L+1] : 0);  
                    result += (A == 0 ? t[i-1][A+1][0]: 0); 
                    t[i][A][L] = result % M;
                }
            }
        }

        return t[n][0][0]; 

    }
};