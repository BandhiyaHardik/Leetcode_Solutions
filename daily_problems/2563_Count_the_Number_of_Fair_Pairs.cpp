class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        long long result = 0;

        for(int i = 0; i < n; i++) {
            int idx = lower_bound(begin(nums) + i + 1, end(nums), lower-nums[i]) - begin(nums);
            int x   = idx - 1 - i;

            idx = upper_bound(begin(nums) + i + 1, end(nums), upper-nums[i]) - begin(nums);

            int y = idx - 1 - i;

            result += (y-x);
        }

        return result;
    }
};
