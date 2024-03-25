class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> result; 
        for(int i = 0; i < n; i++) {
            int num = abs(nums[i]);
            
            if(nums[num-1] < 0) {
                result.push_back(num);
            } else {
                nums[num-1] *= -1;
            }
        }
        
        return result;
        
    }
};
