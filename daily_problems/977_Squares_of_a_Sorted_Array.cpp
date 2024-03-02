class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            nums[i] = nums[i]*nums[i];
        }
        
        sort(begin(nums), end(nums)); 
        return nums;
    }
};