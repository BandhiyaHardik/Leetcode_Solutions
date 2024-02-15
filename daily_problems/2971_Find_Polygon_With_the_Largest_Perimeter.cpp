class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        long long perimeter = 0;
        long long cumSum    = 0;
        
        
        for(int i = 0; i < n; i++) {
            if(nums[i] < cumSum) {
                perimeter = nums[i] + cumSum;
            }
            cumSum += nums[i];
        }
        
        return perimeter == 0 ? -1 : perimeter;
        
    }
};