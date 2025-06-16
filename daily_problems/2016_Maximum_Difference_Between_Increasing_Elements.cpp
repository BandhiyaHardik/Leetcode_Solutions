class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int minElementi = nums[0];
        int maxDiff = -1;

        for(int j = 1; j < n; j++) {
            if(nums[j] > minElementi) {
                maxDiff = max(maxDiff, nums[j] - minElementi);
            } else {
                minElementi = nums[j];
            }
        }

        return maxDiff;
    }
};