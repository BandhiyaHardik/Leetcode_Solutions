class Solution {
public:
    int solve(vector<int>& nums, int &target, int i, int sum, unordered_map<string, int>& memo) {
        if (i == nums.size()) {
            return sum == target ? 1 : 0;
        }

        string key = to_string(i) + "," + to_string(sum);

        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        int plus = solve(nums, target, i + 1, sum + nums[i], memo);
        int minus = solve(nums, target, i + 1, sum - nums[i], memo);

        memo[key] = plus + minus;

        return memo[key];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> memo;
        return solve(nums, target, 0, 0, memo);
    }
};