class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            int n = nums.size();
            long long result = 0;
    
            long long maxDiff = 0;
            long long maxi = 0;
    
            for(int k = 0; k < n; k++) {
                result = max(result, maxDiff * nums[k]);
                maxDiff = max(maxDiff, maxi - nums[k]);
                maxi = max(maxi, (long long)nums[k]);
            }
            return result;
        }
};    