class Solution {
public:
    vector<vector<int>> result;
    int n;
    
    void solve(int idx, vector<int>& nums) {

        if(idx == n) {
            result.push_back(nums);
            return;
        }
        
        for(int i = idx; i < n; i++) {
            swap(nums[i], nums[idx]);
            
            solve(idx+1, nums);
            
            swap(nums[i], nums[idx]);
        }
        
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        
        solve(0, nums);
        
        return result;
    }
};
