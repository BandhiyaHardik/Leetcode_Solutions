class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = 0;
        int result = 0;
        int streak = 0;

        for (int num : nums) {
            if (num > maxVal) {
                maxVal = num;
                result = 0;
                streak = 0;
            }

            if (maxVal == num) {
                streak++;
            } else {
                streak = 0;
            }

            result = max(result, streak);
        }

        return result;
    }
};