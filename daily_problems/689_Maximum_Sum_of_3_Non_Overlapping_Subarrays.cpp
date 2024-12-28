class Solution {
private:
    int t[20001][4];

    int helper(vector<int>& sums, int k, int idx, int rem) {
        if (rem == 0) return 0;
        if (idx >= sums.size()) {
            return INT_MIN;
        }

        if (t[idx][rem] != -1) {
            return t[idx][rem];
        }

        int take = sums[idx] + helper(sums, k, idx + k, rem - 1);
        int not_take = helper(sums, k, idx + 1, rem);

        t[idx][rem] = max(take, not_take);
        return t[idx][rem];
    }

    void solve(vector<int>& sums, int k, int idx, int rem, vector<int>& indices) {
        if (rem == 0) return;
        if (idx >= sums.size()) return;

        int take     = sums[idx] + helper(sums, k, idx + k, rem - 1);
        int not_take = helper(sums, k, idx + 1, rem);

        if (take >= not_take) {
            indices.push_back(idx);
            solve(sums, k, idx + k, rem - 1, indices);
        } else {
            solve(sums, k, idx + 1, rem, indices);
        }
    }

public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {

        memset(t, -1, sizeof(t));

        int n = nums.size() - k + 1;

        vector<int> sums;
        int windowSum = 0;
        int i = 0, j = 0;

        while (j < nums.size()) {
            windowSum += nums[j];

            if (j - i + 1 == k) {
                sums.push_back(windowSum);
                windowSum -= nums[i];
                i++;
            }
            j++;
        }

        vector<int> indices;

        solve(sums, k, 0, 3, indices);

        return indices;
    }
};