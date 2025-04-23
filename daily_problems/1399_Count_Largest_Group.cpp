class Solution {
public:
    int findDigitsSum(int num) {
        int sum = 0;
        while(num) {
            sum += num%10;
            num /= 10;
        }

        return sum;
    }

    int countLargestGroup(int n) {
        unordered_map<int, int> mp;

        int maxSize = 0;
        int count   = 0;

        for(int num = 1; num <= n; num++) {
            int digitsSum = findDigitsSum(num);

            mp[digitsSum]++;
            if(mp[digitsSum] == maxSize) {
                count++;
            } else if(mp[digitsSum] > maxSize) {
                maxSize = mp[digitsSum];
                count   = 1;
            }
        }

        return count;

    }
};