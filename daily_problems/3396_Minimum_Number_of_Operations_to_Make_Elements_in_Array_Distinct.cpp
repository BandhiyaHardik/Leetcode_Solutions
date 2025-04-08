class Solution {
public:
    int n;
    bool check(vector<int>& nums, int start) {
        unordered_set<int> st;
        for (int j = start; j < n; j++) {
            if (st.count(nums[j])) {
                return false;
            }
            st.insert(nums[j]);
        }
        return true;
    }
    int minimumOperations(vector<int>& nums) {
        n = nums.size();
        int ops = 0;
        for (int i = 0; i < n; i += 3) {
            if (check(nums, i) == true) {
                return ops;
            }
            ops++;
        }
        return ops;
    }
};