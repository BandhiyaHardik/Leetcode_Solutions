class Solution {
public:
    vector<vector<long long>>table;
    int mod = 1e9+7;

    long long dfs(vector<int>&nums) {
        int n = nums.size();
        if (n <= 2)
            return 1;
        
        vector<int>left, right;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[0])
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        long long lans = dfs(left) % mod;
        long long rans = dfs(right) % mod;

        int llen = left.size();
        return (((table[n-1][llen] * lans) % mod) * rans) % mod;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        table.resize(n+1);

        for (int i = 0; i < n+1; i++) {
            table[i] = vector<long long>(i+1, 1);
            for (int j = 1; j < i; j++) {
                table[i][j] = (table[i-1][j-1] + table[i-1][j])%mod;
            }
        }
        long long ans = dfs(nums);
        return ans % mod - 1;
    }
};