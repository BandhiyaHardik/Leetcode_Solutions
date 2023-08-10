class Solution {
public:
    int pivot(vector<int>& nums, int l, int r) {
        while(l < r) {
            
            while(l < r && nums[l] == nums[l+1])
                l++;
            
            while(r < l && nums[r] == nums[r-1])
                r--;

            int mid = l + (r-l)/2;
            
            if(nums[mid] <= nums[r]) { 
                r = mid; 
            } else {
                l = mid+1;
            }
        }
        
        return r;
    }
    
    bool binarySearch(vector<int>& nums, int l, int r, int& target) {
        while(l <= r) {
            int mid = l + (r-l)/2;
            
            if(nums[mid] == target)
                return true;
            
            if(nums[mid] < target)
                l = mid+1;
            else
                r = mid-1;
        }
        
        return false;
    }
    
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        
        
        int p = pivot(nums, 0 , n-1);
        cout <<"p = " << p << endl;
        if(binarySearch(nums, 0, p-1, target)) {
            return true;
        }
        
        return binarySearch(nums, p, n-1, target);
            
    }
};