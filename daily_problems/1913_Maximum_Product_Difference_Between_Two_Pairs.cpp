class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        
        return (nums[n-1] * nums[n-2]) - (nums[1] * nums[0]);
    }
};