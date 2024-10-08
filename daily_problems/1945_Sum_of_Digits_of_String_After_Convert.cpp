class Solution {
public:
    int getLucky(string s, int k) {

        string numStr;
        for (char c : s) {
            int value = c - 'a' + 1;
            numStr += to_string(value);
        }
        
        int sum = 0;
        for (char c : numStr) {
            sum += c - '0';
        }

        for (int i = 1; i < k; ++i) {
            int newSum = 0;
            while (sum > 0) {
                newSum += sum % 10;
                sum /= 10;
            }
            sum = newSum;
        }
        
        return sum;
    }
};
