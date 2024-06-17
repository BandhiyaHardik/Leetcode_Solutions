class Solution {
public:
    bool judgeSquareSum(int c) {
        long long a = 0, b = sqrt(c);
        while (a <= b) {
            long long currSum = a * a + b * b;
            if (currSum == c) return true;
            else if (currSum < c) a++;
            else b--;
        }
        return false;
    }
};