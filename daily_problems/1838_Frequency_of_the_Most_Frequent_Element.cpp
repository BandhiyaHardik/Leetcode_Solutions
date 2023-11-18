class Solution {
public:
    int maxFrequency(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        long long sum = 0;
        int left = 0;
        int maxFreq = 0;

        for (int right = 0; right < n; ++right) {
            sum += nums[right];

            while ((long long)(nums[right]) * (right - left + 1) - sum > k) {
                sum -= nums[left];
                ++left;
            }

            maxFreq = std::max(maxFreq, right - left + 1);
        }

        return maxFreq;
    }
};