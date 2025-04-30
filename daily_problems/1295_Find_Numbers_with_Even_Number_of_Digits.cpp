class Solution {
public:
    bool hasEvenDigits(int num) {
        int digitCount = 0;
        while (num) {
            digitCount++;
            num /= 10;
        }
        return (digitCount % 2) == 0;
    }

    int findNumbers(vector<int>& nums) {
        int result = 0;

        for (int num : nums) {
            if (hasEvenDigits(num))
                result++;
        }

        return result;
    }
};