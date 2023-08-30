class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long result = 0;
        
        for(int i = n-2; i >= 0; i--) {

            int splits = nums[i]/nums[i+1];
            
            if((nums[i]) % nums[i+1] != 0) {
                splits++;
            }
            
            nums[i] = nums[i]/splits;
            result += splits-1;
        }
        
        return result;
    }
};
