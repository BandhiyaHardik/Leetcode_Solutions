class Solution {
public:

    int specialArray(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();

        for(int x = 0; x <=n; x++) {
            
            int i = lower_bound(begin(nums), end(nums), x) - begin(nums);

            if(n-i == x) {
                return x;
            }
        }

        return -1;
    }
};
