class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int maxNum = (1 << maximumBit) - 1;
        int xorAll = 0;
        
        for (int num : nums) {
            xorAll ^= num;
        }
        
        vector<int> answer(n);

        for (int i = 0; i < n; ++i) {
            answer[i] = xorAll ^ maxNum;
            xorAll ^= nums[n - 1 - i];
        }
        
        return answer;
    }
};
