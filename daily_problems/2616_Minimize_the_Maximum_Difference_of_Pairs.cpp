class Solution {
public:
    int n;
    
    bool isValid(vector<int>& nums, int mid, int p) {
        
        int i = 0;
        int pairs = 0;
        while(i < n-1) {
            
            if(nums[i+1] - nums[i] <= mid) {
                pairs++;
                i+=2;
            } else {
                i++;
            }
        }
        
        return pairs >= p;
        
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        n = nums.size();
        
        sort(begin(nums), end(nums));
        
        int l = 0;
        int r = nums[n-1] - nums[0];
        
        int result = INT_MAX;
        
        while(l <= r) {
            
            int mid = l + (r-l)/2;
            
            if(isValid(nums, mid, p)) {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
            
        }
        
        return result;
        
    }
};