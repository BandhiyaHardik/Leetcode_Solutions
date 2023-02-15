class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        for(int i = nums.size() - 1; i >= 0; i--) {
            nums[i] += k;
            k = nums[i] / 10;
            nums[i] = nums[i] % 10;
        }
        while(k > 0) {
            nums.insert(nums.begin(), k % 10);
            k /= 10;
        }
        return nums;
    }
};