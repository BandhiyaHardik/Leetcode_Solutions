class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        int maxNum = nums[0];
        int result = 0;
        
        for(int i = 1; i<n; i++) {
            result = max(result, (maxNum-1)*(nums[i]-1));
            maxNum = max(maxNum, nums[i]);
        }
        
        return result;
    }
};