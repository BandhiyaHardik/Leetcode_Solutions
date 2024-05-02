class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int result = -1;
        
        for (int &i : nums) {
            for (int &j : nums) {
                if (i == -j) {
                    result = max(result, abs(i));
                }
            }
        }

        return result;
    }
};