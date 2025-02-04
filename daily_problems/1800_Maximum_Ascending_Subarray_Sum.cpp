class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();

        int maxSum = 0;

        for(int i = 0; i < n; i++) {

            int sum = nums[i];
            int j = i+1;
            while(j < n && nums[j] > nums[j-1]) {
                sum += nums[j];
                j++;
            }

            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};