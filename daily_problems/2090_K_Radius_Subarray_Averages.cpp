class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(k == 0)
            return nums;
    
        vector<int> result(n, -1);
        
        if(n < 2*k + 1)
            return result;
        
        long long windowSum = 0;
        
        int left  = 0;
        int right = 2*k;
        int i     = k;
        
        for(int i = left; i <= right; i++) {
            windowSum += nums[i];
        }
        
        
        result[i] = windowSum/(2*k+1);
        
        i++;
        right++; 
        
        while(right < n) {
            
            int out_of_window  = nums[left];
            int came_to_window = nums[right];
            
            windowSum = windowSum - out_of_window + came_to_window;
            
            result[i] = windowSum/(2*k+1);
            i++;
            left++;
            right++;
            
        }
        return result;
    }
};