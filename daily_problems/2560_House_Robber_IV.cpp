class Solution {
    public:
        bool isPossible(vector<int>& nums, int mid, int k) {
            int house = 0;
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] <= mid) {
                    house++;
                    i++;
                }
            }
    
            return house >= k;
        }
        int minCapability(vector<int>& nums, int k) {
            int n = nums.size();
    
            int l = *min_element(begin(nums), end(nums));
            int r = *max_element(begin(nums), end(nums));
    
            int result = r;
    
            while(l <= r) {
                int mid = l + (r-l)/2;
    
                if(isPossible(nums, mid, k) == true) {
                    result = mid;
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            }
    
            return result;
        }
    };