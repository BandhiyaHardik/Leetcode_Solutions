class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();

        for (int j = 0; j < k; j++) {

            int idx = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] < nums[idx]) {
                    idx = i;
                }
            }

            nums[idx] *= multiplier;
        }

        return nums;
    }
};
