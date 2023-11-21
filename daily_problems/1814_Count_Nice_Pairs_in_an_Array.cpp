class Solution {
public:
    int M = 1e9+7;
    int reverse(int num) {
        int rev = 0;
        
        while(num > 0) {
            int rem = num%10;
            rev = rev*10 + rem;
            num /= 10;
        }
        
        return rev;
    }
    
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, int> mp;

        for(int i = 0; i<n; i++) {
            nums[i] = nums[i] - reverse(nums[i]);
        }
        
        int result = 0;
        for(int i = 0; i<n; i++) {
            
            result = (result + mp[nums[i]]) % M;
            
            mp[nums[i]]++;
        }
        
        return result;
    }
};