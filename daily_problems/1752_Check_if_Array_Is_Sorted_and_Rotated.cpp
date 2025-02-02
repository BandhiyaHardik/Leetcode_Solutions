class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        vector<int> sorted(n);

        for(int r = 0; r < n; r++) {

            int idx = 0;
            for(int i = r; i < n; i++) {
                sorted[idx] = nums[i];
                idx++;
            }

            for(int i = 0; i < r; i++) {
                sorted[idx] = nums[i];
                idx++;
            }

            bool isSorted = true;
            for(int i = 0; i < n-1; i++) {
                if(sorted[i] > sorted[i+1]) {
                    isSorted = false;
                    break;
                }
            }

            if(isSorted) {
                return true;
            }

        }

        return false;
    }
};