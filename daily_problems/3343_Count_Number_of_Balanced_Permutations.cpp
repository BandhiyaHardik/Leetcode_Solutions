class Solution {
public:
    int n;
    int totalDigitSum;
    int M = 1e9 + 7;
    long long totalPermPossible = 0;

    int findPower(long long a, long long b) {
        if(b == 0) {
            return 1;
        }

        long long half = findPower(a, b/2);
        long long result = (half * half) % M;
        if(b % 2 == 1) {
            result = (result * a) % M;
        }

        return result;
    }

    int solve(int digit, int evenIndexDigitsCount, int currSum, 
            vector<int>& freq, vector<long long>& fermatFact, 
            vector<vector<vector<int>>> &t) {
        if(digit == 10) {
            if(currSum == totalDigitSum/2 && evenIndexDigitsCount == (n+1)/2) {
                return totalPermPossible;
            }
            return 0;
        }

        if(t[digit][evenIndexDigitsCount][currSum] != -1) {
            return t[digit][evenIndexDigitsCount][currSum];
        }
        long long ways = 0;

        for(int count = 0; count <= min(freq[digit], (n+1)/2 - evenIndexDigitsCount); count++) {
            int evenPosCount = count;
            int oddPosCount  = freq[digit] - count;

            long long div = (fermatFact[evenPosCount] * fermatFact[oddPosCount])% M;

            long long val = solve(digit+1, evenIndexDigitsCount + evenPosCount, currSum + digit*count, freq, fermatFact, t);

            ways = (ways + (val * div) % M) % M;
        }

        return t[digit][evenIndexDigitsCount][currSum] = ways;
    }

    int countBalancedPermutations(string num) {
        n   = num.length();
        totalDigitSum = 0;

        vector<int> freq(10, 0);
        for(int i = 0; i < n; i++) {
            totalDigitSum += num[i] - '0';
            freq[num[i] - '0']++;
        }

        if(totalDigitSum % 2 != 0) {
            return 0;
        }

        vector<long long> fact(n+1, 1);
        fact[0] = 1;
        fact[1] = 1;
        for(int i = 2; i <= n; i++) {
            fact[i] = (fact[i-1] * i) % M;
        }

        vector<long long> fermatFact(n+1, 1);
        for(int i = 0; i <= n; i++) {
            fermatFact[i] = findPower(fact[i], M-2) % M;
        }

        totalPermPossible = (1LL * fact[(n+1)/2] * fact[n/2]) % M;

        int digit = 0;
        int evenIndexDigitsCount = 0;
        int currSum = 0;
        vector<vector<vector<int>>> t(10, vector<vector<int>>((n + 1) / 2 + 1, vector<int>(totalDigitSum + 1, -1)));
        return solve(digit, evenIndexDigitsCount, currSum, freq, fermatFact, t);

    }
};