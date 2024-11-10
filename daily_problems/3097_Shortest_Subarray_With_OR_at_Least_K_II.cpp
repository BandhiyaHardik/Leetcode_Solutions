class Solution {
public:

    void update(int number, vector<int>& vec, int val) {
        for(int i = 0; i < 32; i++) { 
            if((number >> i) & 1) {
                vec[i] += val;
            }
        }
    }

    int getDecimalFromBinary(vector<int>& vec) {
        int num = 0;

        for(int i = 0; i < 32; i++) {
            if(vec[i] > 0) {
                num |= (1 << i);
            }
        }

        return num;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        int result = INT_MAX;

        int i = 0;
        int j = 0;

        vector<int> vec(32, 0);

        while(j < n) {
            update(nums[j], vec, 1);

            while(i <= j && getDecimalFromBinary(vec) >= k) {
                result = min(result, j-i+1);
                update(nums[i], vec, -1);
                i++;
            }

            j++;
        }

        return result == INT_MAX ? -1 : result;
    }
};
