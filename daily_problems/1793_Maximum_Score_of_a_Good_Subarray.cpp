class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();

        int i = k;
        int j = k;
        int curMin = nums[k];
        
        int result = nums[k];
        
        while(i > 0 || j < n-1) {
            int leftValue;
            int rightValue;
            
            if(i > 0) {
                leftValue = nums[i-1];
            } else {
                leftValue = 0;
            }
            
            if(j < n-1) {
                rightValue = nums[j+1];
            } else {
                rightValue = 0;
            }
            
            if(leftValue < rightValue) {
                j++;
                curMin = min(curMin, nums[j]);
            } else {
                i--;
                curMin = min(curMin, nums[i]);
            }
            
            result = max(result, curMin * (j-i+1));
        }
        
        return result;
    }
};