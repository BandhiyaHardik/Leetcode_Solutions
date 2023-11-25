class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(begin(nums), end(nums), 0);

        vector<int> result(n);
        int prefixSum = 0;
        
        for(int i = 0; i < n; i++) {
            int leftSum   = prefixSum;
            int rightSum  = sum - prefixSum - nums[i];
            
            int leftCount  = i;
            int rightCount = n-i-1;
            
            int leftTotal  = (leftCount * nums[i]) - leftSum;
            int rightTotal = rightSum - (nums[i]*rightCount);
            
            result[i] = leftTotal + rightTotal;
            prefixSum += nums[i];
        }
        
        return result;
        
    }
};